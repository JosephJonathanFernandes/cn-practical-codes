#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void sender();
void receiver(int frame);

int main() {
    sender();
    return 0;
}

void sender() {
    int frame = 0;
    char ch;
    srand(time(NULL)); // for simulating random loss

    while (1) {
        printf("\nSender: Sending frame %d\n", frame);
        receiver(frame);

        printf("Sender: Waiting for ACK...\n");
        int lost = rand() % 4 == 0; // 25% chance to simulate lost ACK

        if (!lost) {
            printf("Sender: ACK %d received\n", frame);
            frame = (frame + 1) % 2;
        } else {
            printf("Sender: ACK lost! Resending frame %d\n", frame);
            continue; // resend same frame
        }

        printf("Send next frame? (y/n): ");
        scanf(" %c", &ch);
        if (ch != 'y') break;
    }
}

void receiver(int frame) {
    printf("Receiver: Frame %d received successfully\n", frame);
    printf("Receiver: Sending ACK %d\n", frame);
}
