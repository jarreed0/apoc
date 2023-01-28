#include "sdltemplate.h"

using namespace sdltemplate;

struct obj {
 std::string name;
 SDL_Rect dest, src;
 int img;
 bool flipH, flipV;
 double angle;
 SDL_Point center;
};

struct weapon : obj {
  int damage;
};

struct melee : weapon {
  double reach;
};

struct gun : weapon {
  int magazine_size;
  int ammo;
  bool is_automatic;
};

struct entity : obj {
 double health, maxHealth;
 weapon* equipped_weapon;
};

void draw(obj* o) {
 //drawImage(o->img, o->dest, o->src);
 drawImage(o->img, o->dest, o->src, o->angle, o->center, o->flipH, o->flipV);
}
void draw(entity* e) {
 //drawImage(e->img, e->dest, e->src);
 drawImage(e->img, e->dest, e->src, e->angle, e->center, e->flipH, e->flipV);
}

obj createObj(int img, SDL_Rect dest, SDL_Rect src) {
 obj o;
 o.img = img;
 o.dest = dest;
 o.src = src;

 //
 o.angle = 0;
 o.center = {0,0};
 o.flipH = false;
 o.flipV = false;

 return o;
}

obj createObj(std::string img, SDL_Rect dest, SDL_Rect src) {
 return createObj(loadImage(img), dest, src);
}

entity createEnt(int img, SDL_Rect dest, SDL_Rect src, double h, double mh) {
 entity e;
 e.img = img;
 e.dest = dest;
 e.src = src;
 e.health = h;
 e.maxHealth = mh;

 //
 e.angle = 0;
 e.center = {0,0};
 e.flipH = false;
 e.flipV = false;

 return e;
}

entity createEnt(std::string img, SDL_Rect dest, SDL_Rect src, double h, double mh) {
 return createEnt(loadImage(img), dest, src, h, mh);
}

void move(obj* o, double x, double y) {
 o->dest.x += x;
 o->dest.y += y;
}
void move(entity* e, double x, double y) {
 e->dest.x += x;
 e->dest.y += y;
}

void goTo(obj* o, double x, double y) {
 o->dest.x = x;
 o->dest.y = y;
}
void goToMouse(obj* o) {
 goTo(o, mouse.x, mouse.y);
}
void goTo(entity* e, double x, double y) {
 e->dest.x = x;
 e->dest.y = y;
}
void goToMouse(entity* e) {
 goTo(e, mouse.x, mouse.y);
}
