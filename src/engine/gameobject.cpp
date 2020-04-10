#include "gameobject.h"

GameObject::GameObject(const char* name)
    : parent(nullptr), children(std::vector<GameObject*>()), name(std::string(name))
{

}

GameObject::~GameObject() {
    this->free();
}

void GameObject::add_child(GameObject *child) {
    this->children.push_back(child);
    child->parent = this;
}

void GameObject::_update(float delta) {
    this->update(delta);
    for (auto child : this->children)
        child->_update(delta);
}

void GameObject::_draw() {
    this->draw();
    for (auto child : this->children)
        child->draw();
}

void GameObject::free() {

}

std::vector<GameObject*> &GameObject::get_children() {
    return this->children;
}

size_t GameObject::find_in_parent() {
    if (this->parent) {
        for (size_t i = 0; i < parent->children.size(); ++i) {
            if (parent->children[i] == this)
                return i;
        }
    }
    return 0;
}

const std::string &GameObject::get_name() {
    return this->name;
}

void GameObject::set_name(std::string &value) {
    this->name = value;
}

void GameObject::set_name(const char *value) {
    this->name = std::string(value);
}
