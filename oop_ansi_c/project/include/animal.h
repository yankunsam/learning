/*************************************************************************
	> File Name: animal.h
	> Author: 
	> Mail: 
	> Created Time: 2016年07月05日 星期二 16时45分05秒
 ************************************************************************/

#ifndef _ANIMAL_H
#define _ANIMAL_H
struct animal
{
    const struct animal_vtable_ *vtable_;
    const char *name;
};

struct animal_vtable_ 
{
    const char *(*sound)(void);
};

static inline const char *animal_sound(struct animal *animal)
{
    return animal->vtable_->sound();
}
extern const struct animal_vtable_ CAT[],DOG[];
#endif
