#include <stdio.h>


struct Box {
    float length;
    float width;
    float height;
};


float calculateVolume(struct Box* box) 
{
    return box->length * box->width * box->height;
}


float calculateSurfaceArea(struct Box* box) 
{
    return 2 * (box->length * box->width + box->width * box->height + box->height * box->length);
}

int main() {
    
    struct Box box;
    box.length = 4.5;
    box.width = 2.7;
    box.height = 3.8;

   
    struct Box* boxPtr = &box;
    float volume = (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
    float surfaceArea = 2 * ((*boxPtr).length * (*boxPtr).width + (*boxPtr).width * (*boxPtr).height + (*boxPtr).height * (*boxPtr).length);

    printf("Using pointer and dot operator:\n");
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    
    float volume2 = boxPtr->length * boxPtr->width * boxPtr->height;
    float surfaceArea2 = 2 * (boxPtr->length * boxPtr->width + boxPtr->width * boxPtr->height + boxPtr->height * boxPtr->length);

    printf("\nUsing arrow operator:\n");
    printf("Volume: %.2f\n", volume2);
    printf("Surface Area: %.2f\n", surfaceArea2);

    return 0;
}