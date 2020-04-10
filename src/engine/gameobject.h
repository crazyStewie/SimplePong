#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<vector>
#include<cstdlib>
#include<string>

class GameObject
{
public:
    explicit GameObject(const char* name);
    ~GameObject();
    /// @brief Update function called each frame, override this with your own code to create custom objects
    virtual void update(float delta) = 0;

    void _update(float delta);

    virtual void draw() = 0;

    void _draw();
    /// @brief Adds a child to this GameObject
    /// @param[in] Child pointer to the GameObject to be added
    void add_child(GameObject *child);

    /// @brief Returns the children of this GameObject
    /// @return Reference to a vector of GameObject pointers
    std::vector<GameObject*> &get_children();

    /// @brief Deletes this GameObject and all of it's children from memory
    void free();

    const std::string &get_name();

    void set_name(std::string &value);

    void set_name(const char* value);

private:
    size_t find_in_parent();
private:
    GameObject *parent;
    std::vector<GameObject*> children;
    std::string name;
};

#endif // GAMEOBJECT_H
