#pragma once

//#define WINDOW_SIZE_X 1000
//#define WINDOW_SIZE_Y 750
#define WINDOW_SIZE_X 1920
#define WINDOW_SIZE_Y 1080

#define LOCATION_OVERWORLD_LEVEL_1 "levels/Level 1/overworld.json"
#define LOCATION_VOID_LEVEL_1 "levels/Level 1/void.json"

#define LOCATION_OVERWORLD_LEVEL_2 "levels/Level 2/overworld.json"
#define LOCATION_VOID_LEVEL_2 "levels/Level 2/void.json"

#define LOCATION_OVERWORLD_LEVEL_3 "levels/Level 3/overworld.json"
#define LOCATION_VOID_LEVEL_3 "levels/Level 3/void.json"

#define FRAME_RATE 60

inline int rand_range(int start, int end) {
    return start + (std::rand() % (end - start + 1));
}

//struct tile_priority {
//    std::string tile;
//    unsigned int priority;
//
//    tile_priority(std::string t, int p) :
//        tile(t)/*,
//        priority(priority)*/
//    {
//        /*if (p < 0) {
//            priority = 0;
//        }
//        else {
//            priority = p;
//        }*/
//        p < 0 ? priority = 0 : priority = p;
//    }
//};
