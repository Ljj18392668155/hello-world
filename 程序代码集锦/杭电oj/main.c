#include <stdio.h>
#include <stdlib.h>

int main()
{
   float y,f;
    for ( y = 1.5f; y > -1.5f; y -= 0.1f)
    {
        float x;
        for ( x = -1.5f; x < 1.5f; x += 0.05f)
        {
            float z = x * x + y * y - 1;
            float f = z * z * z - x * x * y * y * y;
            putchar(f <= 0.0f ? ".:-=+*#%@"[(int)(f * -8.0f)] : ' ');
        }
        putchar('\n');
    }

  printf("|             * * * *      *     *     * * * *             |\n");
  printf("|                  *        *   *           *              |\n");
  printf("|                *            *           *                |\n");
  printf("|              *              *         *                  |\n");
  printf("|             * * * *         *        * * * *             |\n");
  printf("|                                                          |\n");
  printf("|                                                          |\n");
  printf("|                                                          |\n");
  printf("------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n                                                   |\n");
    return 0;
}
