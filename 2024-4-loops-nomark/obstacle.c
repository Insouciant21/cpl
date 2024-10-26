#include <stdio.h>
#include <stdlib.h>

int main() {
    int Ax, Ay, Bx, By, Cx, Cy;
    scanf("%d%d%d%d%d%d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
    Bx -= Ax, By -= Ay, Cx -= Ax, Cy -= Ay, Ax = Ay = 0;
    int maxX = Ax > Bx ? Ax : Bx, maxY = Ay > By ? Ay : By;
    int minX = Ax < Bx ? Ax : Bx, minY = Ay < By ? Ay : By;
    if (!(minX <= Cx && Cx <= maxX && minY <= Cy && Cy <= maxY) || (minX < Cx && Cx < maxX && minY < Cy && Cy < maxY)) {
        printf("%d\n", abs(Bx) + abs(By));
        for (int i = 0; i < abs(Bx); i++) 
            printf(Bx > 0 ? "R" : "L");
        for (int i = 0; i < abs(By); i++) 
            printf(By > 0 ? "U" : "D");
    }
    else if (Ax == Bx && Bx == Cx) {
        printf("%d\nL", abs(Bx) + abs(By) + 2);
        for (int i = 0; i < abs(By); i++) printf(By > 0 ? "U" : "D");
        printf("R");
    }
    else if (Ay == By && By == Cy) {
        printf("%d\nU", abs(Bx) + abs(By) + 2);
        for (int i = 0; i < abs(Bx); i++) printf(Bx > 0 ? "R" : "L");
        printf("D");
    }
    else {
        printf("%d\n", abs(Bx) + abs(By));
        if (By == Cy || Ax == Cx) {
            for (int i = 0; i < abs(Bx); i++) printf(Bx > 0 ? "R" : "L");
            for (int i = 0; i < abs(By); i++) printf(By > 0 ? "U" : "D");
        }
        if (Bx == Cx || Cy == Ay) {
            for (int i = 0; i < abs(By); i++) printf(By > 0 ? "U" : "D");
            for (int i = 0; i < abs(Bx); i++) printf(Bx > 0 ? "R" : "L");
        }
    }
    return 0;
}