#ifndef HITTABLE_LIST_HPP

#define HITTABLE_LIST_HPP

#include "Hittable.hpp"

#include <memory>
#include <vector>

class HittableList : public Hittable{
public:
    HittableList();
    HittableList(std::shared_ptr<Hittable>);
    void clear();
    void add(std::shared_ptr<Hittable>);
    virtual bool hit(const Ray&, double, double, HitRecord&) const override;
private:
    std::vector<std::shared_ptr<Hittable>> objects;
};

#endif
