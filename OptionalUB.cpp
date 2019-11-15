#include <optional>
#include <iostream>
#include <vector>
#include <algorithm>

#if defined(__has_feature)
#  if __has_feature(memory_sanitizer)
// code that builds only under MemorySanitizer
    #pragma message("code that builds only under MemorySanitizer") 
#  endif
#endif

using namespace std;

/* obvious example */
int returnOptional() {
    optional<int> x(nullopt);
    return *x;
}


/* a good working example for demonstrating reasons */
void goodExample() {
    auto value = make_optional<string>("This is an optional string");
    if (value.has_value()) {
       cout << value.value() << endl;
    } else {
        cout << "No value" << endl;
    }

    optional<int> anotherValue = 42;
    cout << anotherValue.value() << endl;
}

class User {
    private:
        string userName;
        string userRole;
    public:
        User(string name, string role) : userName(name), userRole(role) { };
        ~User() = default;
        bool operator==(const User& rhs) {
            if (this->userName == rhs.userName){
                return true;
            } else {
                return false;
            }
        }
        string operator() () {
            string result = this->userName + ":" + this->userRole;
            return result;
        }
};

class UserManager {
    private:
        vector<User> users;
    public:
        UserManager() = default;
        ~UserManager() = default;

        void addUser(User user) {
            this->users.emplace_back(user);
        }

        void addUser(string userName, string userRole) {
            User user(userName, userRole);
            addUser(user);
        }

        optional<User> findUser(string name) {
            User userLookingFor(name, "default");
            auto result = find(users.begin(), users.end(), userLookingFor);

            if (result != users.end()) {
                return *result;
            }  else {
                return nullopt;
            }
        }
};

auto checkUser(UserManager manager, string user) {
    auto hit = manager.findUser(user);
    auto result(hit);
    return *result;
}

User checkUserValid(UserManager manager, string user) {
    auto hit = manager.findUser(user);
    if (hit.has_value()) {
        return hit.value();
    } else {
        throw "User is not registered yet!";
    }
}

int main() {

    UserManager manager;

    manager.addUser("kfejes", "admin");
    manager.addUser("johnsmiths", "regularuser");
    manager.addUser("johnsmiths42", "superadmin");
    manager.addUser("gezaX", "superuser");

    auto found = checkUserValid(manager, "johnsmiths42");
    try {
        auto notFound = checkUserValid(manager, "error");
    } catch ( const char* e ) {
        cout << "Error: " << e << endl;
    }

    cout << found() << endl;

    // auto value = returnOptional();
    // cout << value << endl;

    return EXIT_SUCCESS;
}

/* 
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=leak-out.txt ./OptionalUB.app
*/ 