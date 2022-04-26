#include "../headers/HittableList.hpp"

HittableList::HittableList(){}

HittableList::HittableList(std::shared_ptr<Hittable> object){
    add(object);
}

void HittableList::clear(){
    objects.clear();
}

void HittableList::add(std::shared_ptr<Hittable> object){
    objects.push_back(object);
}

bool HittableList::hit(const Ray& ray, double minimumTime, double maximumTime, HitRecord& record) const{
    HitRecord temporaryRecord;
    bool hitAnything = false;
    double closestSoFar = maximumTime;

    for(const std::shared_ptr<Hittable>& object : objects){
        if(object->hit(ray, minimumTime, closestSoFar, temporaryRecord)){
            hitAnything = true;
            closestSoFar = temporaryRecord.time;
            record = temporaryRecord;
        }
    }
    return hitAnything;
}
