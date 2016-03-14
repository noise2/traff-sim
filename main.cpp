#include "inc/stdafx.hpp"
#include <thread>

#include "inc/joint.hpp"
#include "inc/street.hpp"

int main(int, char**) {
#ifdef QTCTREATOR
    updateseed();
#else
    std::thread([](){ while(true) { updateseed(); usleep(100000 /*100 milliseconds*/); } }).detach();
#endif
    // city contains some joints connecting the streets
    // streets contain zero or more cars
    // streets are two-way in each direction
    // streets DRIVES the cars that are bound to them
    // a traffic report sent from streets/joints to TCU
    // TCU monitors/predicts/changes the lights/reports status
    street_ptr s0(new street(10, "s0"));
    FOR(i,0,4,++) {
        car_ptr c(new car("C-"+to_string(i)));
        c->direction(i < 2 ? HEAD : TAIL);
        assert(s0->inBoundCar(c, (i < 2 ? TAIL : HEAD)));
        c->max_speed(4.8);
        cout<<"CAR "<<*c<<endl;
    }
    FOR(i,0,5,++) { s0->flow(); }
    FOR(i,4,8,++) {
        car_ptr c(new car("C-"+to_string(i)));
        c->direction(i < 6 ? HEAD : TAIL);
        assert(s0->inBoundCar(c, (i < 6 ? TAIL : HEAD)));
        c->max_speed(20);
        cout<<"CAR "<<*c<<endl;
    }
    joint j;
    j.jointStreet(s0, HEAD);
    j.jointStreet(s0, TAIL);
    j.jointStreet(street_ptr(new street(20, "s2")), TAIL);
    j.jointStreet(street_ptr(new street(20, "s3")), TAIL);
    j.jointStreet(street_ptr(new street(20, "s4")), TAIL);
    j.dispatch_event(street::ON_EXIT, [](vector<const void*> args) {
        const car* c = reinterpret_cast<const car*>(args.front());
        cout<<"Car#: «" << c->getID() <<"» Dir: «" << ::to_string(c->direction()) << "» Line: «"<<c->line()<<"» Speed: «"<<c->max_speed()<<"» Exiting the: " << c->getTour().back() << endl;
    });
    j.branches().back()->traffic_weight() = 2;
    cout<<"----"<<endl;
    size_t x = 0;
    cout<<j;
    while(x < j.size()) {
        FOR(i,0,j.size(),++) {
            bool hhf, thf;
            j[i]->flow(1, &hhf, &thf);
            if(!(hhf || thf)) x++; else x = 0;
        }
    }
    cout<<j;
    return EXIT_SUCCESS;
}
