#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL 10
#define WINDOW 4

int main() {
    int i = 0;
    int retry_count = 0;
    srand(time(0));

    printf("Go-Back-N Sliding Window Simulation\n");

    while (i < TOTAL) {
        int end = i + WINDOW;
        if (end > TOTAL) end = TOTAL;

        printf("\nSending frames: ");
        for (int j = i; j < end; j++) {
            printf("%d ", j);
        }

        // Simulate loss or success (80% success rate)
        int simulate_loss = rand() % 5 == 0; // 1 in 5 chance of loss
        int loss;

        if (simulate_loss) {
            loss = i + rand() % (end - i);
            printf("\nSimulated loss at frame %d", loss);
        } else {
            loss = end;  // No loss
            printf("\nAll frames received successfully.");
        }

        printf("\nReceiver got: ");
        for (int j = i; j < loss; j++) {
            printf("%d ", j);
        }

        printf("\nACK sent till frame %d\n", loss - 1);

        // Move to next frame
        i = loss;
    }

    printf("\nAll frames sent and acknowledged.\n");
    return 0;
}
