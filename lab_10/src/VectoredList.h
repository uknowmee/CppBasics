//
// Created by Michał on 20.05.2021.
//

#ifndef LAB_10_VECTOREDLIST_H
#define LAB_10_VECTOREDLIST_H
#include <iostream>
#include <string>
using namespace std;


class VectoredList {
public:

    class Bucket{
    private:
        static const int N = 10;
        string aggregation[N];
        Bucket* previous;
        Bucket* next;
        int num_of_elements;

    public:
        Bucket(Bucket* p, Bucket* n);
        ~Bucket();

        Bucket* get_previous()const{return previous;};
        Bucket* get_next()const{return next;};
        static int get_size(){return N;};
        int get_num_of_elements()const{return num_of_elements;};
        string& get_exact_element(int index){return aggregation[index];};

        void set_next(Bucket* n){next = n;};
        void plus_num_of_elements(){num_of_elements++;};
        void minus_num_of_elements(){num_of_elements--;};

        void add_string(int i, string t_p);
        void delete_string(int to_delete);
    };

    class VectoredListIterator{
    private:
        const VectoredList& vList;
        Bucket* buck_point;
        const int global_cursor_init_one;

    public:
        int cursor;

        VectoredListIterator(const VectoredList& v, int num);
        ~VectoredListIterator();

        [[maybe_unused]] VectoredList get_VectoredList() const{return vList;};
        int get_global_cursor() const{return global_cursor_init_one;};
        string get()const{return buck_point->get_exact_element(cursor);};
        Bucket* get_bucket_point()const{return buck_point;};
        int get_VectoredListSize()const{
            return Bucket::get_size()*(vList.size-1)+vList.tail->get_num_of_elements();};


        VectoredListIterator& operator--();
        VectoredListIterator& operator++();
        bool operator!=(VectoredListIterator &check)const;
        const string& operator*();

        bool good()const;
    };

private:
    Bucket* head;
    Bucket* tail;
    int size;
    int capacity;

public:
    VectoredList();
    VectoredList(const VectoredList& to_be_copied);
    ~VectoredList();

    ///getter
    int VectoredListSize()const{
        return Bucket::get_size()*(size-1)+tail->get_num_of_elements();}

    string& operator[](int index)const;
    VectoredList& operator=(const VectoredList& to_be_copied);

    void push_back(const string& to_push);
    void delete_front();
    void pop_back();
    void erase(const VectoredListIterator& to_delete);
    void erase(const VectoredListIterator& to_delete_beg,
               const VectoredListIterator& to_delete_end);
    VectoredListIterator begin()const;
    VectoredListIterator end()const;
};


#endif //LAB_10_VECTOREDLIST_H
