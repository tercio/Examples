#include <iostream>
#include <vector>


using namespace std;


class observer {

    public:
        virtual void notify () = 0;
};

class subject {

    public:
        void addObserver (observer *o) {
            observers.push_back(o);
        }
        void notifyAll () {

            for (int i=0; i < observers.size(); i++) {
                observers[i]->notify();
            }
        }
    private:
        vector<observer *> observers;
};

//=============================================================

class db : public subject {

public:
    void run () {

        for (int i=0; i < 5; i++) {
            notifyAll();
            sleep (2);
        }
    }
};

class window : public observer {

    void notify () {
        cout << "window: notification received" << endl;
    }
};

class console : public observer {

    void notify () {
        cout << "console:  notification received" << endl;
    }
};

int
main () {

    db *d = new db();

    window *w = new window();
    console *c = new console();

    d->addObserver (w);
    d->addObserver (c);

    d->run();

    return 0;
}
