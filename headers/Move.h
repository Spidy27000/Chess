#ifndef MOVE_H
#define MOVE_H

#include "Vec2.h"

// enum MoveType{
//     NormalMove,
//     Enpassnt,
//     Castle,
//     Capture,
//     PawnCapure,
//     Check,
//     DoublePawnMove,
//     None
// };

struct sMove
{
    Vec2 sPos;
    Vec2 ePos;

    bool operator==(const sMove& rhs){
        return (this->sPos== rhs.sPos) && (this->ePos== rhs.ePos);
    }
    
};

class Move{    
public:
    Move(){}


};

#endif