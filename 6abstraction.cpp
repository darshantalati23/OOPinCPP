#include <bits/stdc++.h>
#include "bird.h"
using namespace std;

void doWork(Bird *&a) {
    a->eat();
    a->fly();
    a->eat();
    a->fly();
    a->eat();
    a->fly();
    a->eat();
    a->fly();
}

int main() {
    Bird *a = new Eagle();
    doWork(a);
    delete(a);
    return 0;
}