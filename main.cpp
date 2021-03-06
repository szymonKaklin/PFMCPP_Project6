/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* x) : value(v), name(x) {} //1
    int value; //2
    std::string name; //3
};

struct Comparator                            //4
{
    Comparator() {}
    T* compare(T& a, T& b) //5
    {
        // this function returns pointers, so I didn't convert to reference types. I did however change it to be pass by reference, and return the memory address of a and b, which should work the same as the previous implementation. Is my understanding of this correct?
        // Since these aren't local variables (therefore aren't being destroyed at end of function lifetime), there shouldn't be a problem with undefined behavior as well, right?
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float first { 0 }, second { 0 };
    float memberFunction(const float& newValue)     //12
    {
        std::cout << "U's first value: " << first << std::endl;
        first = newValue;
        std::cout << "U's first updated value: " << first << std::endl;
        while( std::abs(second - first) > 0.001f )
        {
            if( second > first )
            {
                first += 0.001f;
            }
            else
            {
                second += 0.001f;
            }
        }
        std::cout << "U's second updated value: " << second << std::endl;
        return second * first;
    }
};

struct structTwo
{
    static float staticFunctionA(U& that, const float& newValue)        //10
    {
        std::cout << "U's first value: " << that.first << std::endl;
        that.first = newValue;
        std::cout << "U's first updated value: " << that.first << std::endl;
        while( std::abs(that.second - that.first) > 0.001f )
        {
            /*
            write something that makes the distance between that->second and that->first get smaller
            */
            if( that.second > that.first )
            {
                that.first += 0.001f;
            }
            else
            {
                that.second += 0.001f;
            }
        }
        std::cout << "U's second updated value: " << that.second << std::endl;
        return that.second * that.first;
    }
};
        
int main()
{
    T first(7, "first");                                            //6
    T second(7, "second");                                             //6
    
    // Since pointer is being returned here, I did not change the usage.
    Comparator f;                                            //7
    auto* smaller = f.compare(first, second);                              //8
    if( smaller != nullptr )
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "both are the same or nullptr present" << std::endl;
    }
    
    
    U thirdTest;
    float updatedValue = 5.f;
    std::cout << "[static func] thirdTest's multiplied values: " << structTwo::staticFunctionA( thirdTest, updatedValue ) << std::endl;                  //11
    
    U fourthTest;
    std::cout << "[member func] fourthTest's multiplied values: " << fourthTest.memberFunction( updatedValue ) << std::endl;
}
