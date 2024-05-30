#include <iostream>
#include <list>
using namespace std;

class FakeList : public list<int>{
    public:
        FakeList(const list<int>& lst) : list<int>(lst) {}

        int getFakeSize() const{
            return this->size()*2;
        }

        void insert(int el) {
            int check = 0;
            for(auto l: *this){
                if(l==el){
                    this->push_back(el);
                    check++;
                }
            }
            if(check==0){
                this->push_front(el);
            }
        }

        void fakeSort(bool s) {
            if (s) {
                this->sort();
            } else {
                this->sort(greater<int>());
            }
        }

        void fakeClear(bool c) {
            if (c) {
                this->clear();
            }
        }
};

int main() {
    list<int> myList = { 2, 1, 5, 4, 3 };

    FakeList fakeList(myList);

    fakeList.insert(2);

    for (auto i : fakeList) {
        cout << i << " ";
    }
    cout << endl;

    fakeList.fakeSort(true);

    for (auto i : fakeList) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}