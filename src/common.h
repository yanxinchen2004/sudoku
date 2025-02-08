#ifndef SUDOKU_COMMON_H_
#define SUDOKU_COMMON_H_

static const unsigned int UNSELECTED = 0;

// 作用域内枚举 ：后面是代表枚举使用什么类型 
enum class Difficulty : int{
    EASY = 1, // 从1开始，后面递增
    NORMAL,
    HARD
};

enum class State : int{
    INITED = 0,
    ERASED
};

enum class KeyMode : int{
    NORMAL = 1,
    VIM
};

struct KeyMap
{
    const char ESC = 0x1B;
    const char U = 0x75;
    char UP;
    char LEFT;
    char DOWN;
    char RIGHT;
    const char ENTER = 0x0D;
};

struct Normal : KeyMap
{
    Normal()
    {
        UP = 0x77;
        LEFT = 0x61;
        DOWN = 0x73;
        RIGHT = 0x64;
    }
};

struct VIM : KeyMap
{
    VIM()
    {
        UP = 0x6B;
        LEFT = 0x68;
        DOWN = 0x6A;
        RIGHT = 0x6C;
    }
};

using point_t = struct point_t 
{
    int x;
    int y;
};

using point_value_t = struct point_value_t {
    int value;
    State state;
};

class CPointSort
{
    public:
        bool operator()(const point_t &lhs, const point_t &rhs) const
        {
            if((lhs.x == rhs.x) && (lhs.y == lhs.y))
                return false;
            else    
                return true;
        }
};

#endif
