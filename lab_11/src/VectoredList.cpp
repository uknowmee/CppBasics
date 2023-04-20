//
// Created by Michał on 20.05.2021.
//

#include "VectoredList.h"

VectoredList::VectoredList() {
    head = nullptr;
    tail = head;
    size = 0;
    capacity = 0;
}

VectoredList::VectoredList(const VectoredList& to_be_copied) {
    head = nullptr;
    tail = head;
    size = 0;
    capacity = 0;
    if (this!=&to_be_copied){
        for (int i = 0; i < to_be_copied.VectoredListSize(); ++i) {
            this->push_back(to_be_copied[i]);
        }
    }
}

VectoredList::VectoredList(VectoredList&& to_be_copied) noexcept{
    if(to_be_copied.head){
        this->head=to_be_copied.head;
        this->tail=to_be_copied.tail;
        this->size=to_be_copied.size;
        this->capacity=to_be_copied.capacity;
        to_be_copied.head= nullptr;
        to_be_copied.tail= nullptr;
        to_be_copied.size= 0;
        to_be_copied.capacity= 0;
    }
}

VectoredList::~VectoredList() {
    while (head!= nullptr){
        delete_front();
    }
}

string& VectoredList::operator[](int index) const{
    Bucket* range = this->head;
    int exact_index = index%Bucket::get_size();
    for (int i = 0; i < index/Bucket::get_size(); ++i) {
        range = range->get_next();
    }
    return range->get_exact_element(exact_index);
}

VectoredList& VectoredList::operator=(const VectoredList& to_be_copied) {
    if (this!=&to_be_copied){
        for (int i = 0; i < to_be_copied.VectoredListSize(); ++i) {
            this->push_back(to_be_copied[i]);
        }
    }
    return *this;
}

VectoredList& VectoredList::operator=(VectoredList&& to_be_copied) noexcept{
    if(&to_be_copied!=this){
        while (this->head!= nullptr){
            delete_front();
        }
        this->head=to_be_copied.head;
        this->tail=to_be_copied.tail;
        this->size=to_be_copied.size;
        this->capacity=to_be_copied.capacity;
        to_be_copied.head= nullptr;
        to_be_copied.tail= nullptr;
        to_be_copied.size= 0;
        to_be_copied.capacity= 0;
    }
    return *this;
}

VectoredList VectoredList::operator+(const VectoredList& rhs) const {
    VectoredList to_be_returned;
    for (int i = 0; i < this->VectoredListSize(); ++i){
        to_be_returned.push_back(this->operator[](i));
    }
    for (int i = 0; i < rhs.VectoredListSize(); ++i){
        to_be_returned.push_back(rhs[i]);
    }
    return to_be_returned;
}

void VectoredList::push_back(const string& to_push) {
    if (size==0){
        head = new Bucket(nullptr, nullptr);
        tail = head;
        size = 1;
        capacity = Bucket::get_size()-1;
        head->add_string(head->get_num_of_elements(),to_push);
        head->plus_num_of_elements();
    }
    else if (size!=0 && capacity==0){
        tail = new Bucket(tail, nullptr);
        tail->get_previous()->set_next(tail);
        size++;
        capacity+=Bucket::get_size()-1;
        tail->add_string(tail->get_num_of_elements(),to_push);
        tail->plus_num_of_elements();
    }
    else{
        capacity--;
        tail->add_string(tail->get_num_of_elements(),to_push);
        tail->plus_num_of_elements();
    }
}

void VectoredList::delete_front() {
    Bucket* to_delete = head;
    head=head->get_next();
    delete to_delete;
}

void VectoredList::pop_back() {
    if (size==0){
        cout<<"size is 0 cant pop_back"<<endl;
    }
    else if (capacity==9){
        Bucket* to_delete = tail;
        tail=tail->get_previous();
        tail->set_next(nullptr);
        size--;
        capacity=0;
        delete to_delete;
    }
    else{
        tail->delete_string(tail->get_num_of_elements()-1);
        tail->minus_num_of_elements();
        capacity++;
    }
}

void VectoredList::erase(const VectoredList::VectoredListIterator& to_delete) {
    to_delete.get_bucket_point()->delete_string(to_delete.cursor);
    for (int i = 0; i < to_delete.get_VectoredListSize()-1; ++i) {
        if (this->operator[](i).empty()){
            for (int j = i; j < to_delete.get_VectoredListSize()-1; ++j) {
                this->operator[](j)= this->operator[](j+1);
            }
            break;
        }
    }
    this->pop_back();
}

void VectoredList::erase(const VectoredList::VectoredListIterator& to_delete_beg,
                         const VectoredList::VectoredListIterator& to_delete_end) {
    for (int i = 0; i < to_delete_end.get_global_cursor()-to_delete_beg.get_global_cursor()+1; ++i) {
        this->erase(to_delete_beg);
    }
}

VectoredList::VectoredListIterator VectoredList::begin()const {
    return VectoredListIterator(*this, 0);
}

VectoredList::VectoredListIterator VectoredList::end()const {
    return VectoredListIterator(*this, (this->size-1)*Bucket::get_size() + this->tail->get_num_of_elements());
}

void VectoredList::assign(vector<string>& to_be_assigned) {
    for (auto & i : to_be_assigned) {
        this->push_back(i);
    }
    unsigned v_size = to_be_assigned.size();
    for (int i = 0; i < v_size; ++i) {
        to_be_assigned.pop_back();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

VectoredList::Bucket::Bucket(Bucket* p, Bucket* n) {
    previous = p;
    next = n;
    num_of_elements = 0;
}

VectoredList::Bucket::~Bucket() = default;

void VectoredList::Bucket::add_string(int i, string t_p) {
    aggregation[i]=move(t_p);
}

void VectoredList::Bucket::delete_string(int to_delete) {
    aggregation[to_delete]="";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

VectoredList::VectoredListIterator::VectoredListIterator(const VectoredList& v, int num): vList(v), global_cursor_init_one(num) {
    buck_point = v.head;
    cursor = 0;
    for (int i = 0; i < num/Bucket::get_size(); ++i) {
        buck_point = buck_point->get_next();
    }
    if (num!=0){
        cursor = num%10-1;
    }
    else{
        cursor = 0;
    }
}

VectoredList::VectoredListIterator::~VectoredListIterator() = default;

VectoredList::VectoredListIterator& VectoredList::VectoredListIterator::operator--() {
    if (this->cursor==0){
        this->buck_point = this->buck_point->get_previous();
        this->cursor=9;
    }
    else{
        --this->cursor;
    }
    return *this;
}

VectoredList::VectoredListIterator &VectoredList::VectoredListIterator::operator++() {
    if (this->cursor==9){
        this->buck_point = this->buck_point->get_next();
        this->cursor=0;
    }
    else{
        ++this->cursor;
    }
    return *this;
}

bool VectoredList::VectoredListIterator::operator!=(VectoredList::VectoredListIterator &check) const {
    if (this->buck_point == check.buck_point && this->cursor==check.cursor+1){
        return false;
    }
    else{
        return true;
    }
}

const string& VectoredList::VectoredListIterator::operator*() {
    return this->buck_point->get_exact_element(this->cursor);
}

bool VectoredList::VectoredListIterator::good() const {
    if (this->buck_point!= nullptr) {
        return true;
    }
    return false;
}

