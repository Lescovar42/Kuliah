#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h> // For usleep

// Source - https://stackoverflow.com/a
// Posted by Adi Shavit, modified by community. See post 'Timeline' for change history
// Retrieved 2025-11-19, License - CC BY-SA 3.0

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];

    printf("\x1b[2J"); // Clear the screen entirely once

    while(1) {
        // Reset the buffers
        // b[] is the character buffer (the screen)
        // z[] is the Z-buffer (depth buffer) to handle 3D occlusion
        memset(b, 32, 1760); // Fill with spaces (ASCII 32)
        memset(z, 0, 7040);  // Fill with 0s (1760 floats * 4 bytes)

        // Theta (j) rotates around the cross-sectional circle of the torus
        for(j=0; j < 6.28; j += 0.07) {
            // Phi (i) rotates around the center of the torus
            for(i=0; i < 6.28; i += 0.02) {
                
                // Pre-calculate sines and cosines
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2; // Distance from torus center (R2) + circle radius (R1*d)
                float D = 1 / (c * h * e + f * g + 5); // Inverse depth (1/z)
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                
                // Calculate 2D screen coordinates (x, y) using 3D projection
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                
                // Calculate luminance (L) ranges from -sqrt(2) to +sqrt(2)
                // derived from the surface normal dot product with light vector
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

                // If the pixel is on screen, close to the viewer, and illuminated:
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    // Select ASCII character based on luminance
                    // ".,-~:;=!*#$@" gives a gradient from dark to light
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        // Move cursor to home position (top-left)
        printf("\x1b[H");
        
        // Print the buffer to the terminal
        for(k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10); // 10 is ASCII for newline
        }

        // Rotate parameters for the next frame
        A += 0.04;
        B += 0.02;
        
        // Sleep to control animation speed (nanoseconds)
        struct timespec ts = {0, 3000}; // 30ms in nanoseconds
        nanosleep(&ts, NULL);
    }

    return 0;
}