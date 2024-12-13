#ifndef CLAWPACK46BLOCK_H
#define CLAWPACK46BLOCK_H

class Clawpack46Block {
public:
    static void setBlock(int blockno);
    static int getBlock();
    static void unsetBlock();

private:
    static int blockno_com;
};

#endif // CLAWPACK46BLOCK_H