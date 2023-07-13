#ifndef _SELECT_H
#define _SELECT_H 1

#include "types.h"
/*
 * Constants for Operation Types
 */
#define OP_SEND 0 // Constant for Send operation type
#define OP_RECV 1 // Constant for Receive operation type

/*
 * Structure: select_set_t
 * -----------------------
 * This structure represents a set of send or receive operations
 * on multiple channels. Each operation is defined by the channel 
 * descriptor, the operation type, the data to be sent (for send operations), 
 * and the address where the received data should be stored (for receive operations).
 * 
 * Members:
 *    cd:     The channel descriptor.
 *    op_type: The operation type. This should be either OP_SEND or OP_RECV.
 *    send:   A pointer to the data to be sent. This should be NULL for receive operations.
 *    recv:   A pointer to a location where the received data should be stored. This should be NULL for send operations.
 */
typedef struct {
    int cd;
    int op_type;
    any_t *send;
    any_t *recv;
} select_set_t;

/*
 * Function: send_chan
 * -------------------
 * This function sends data to a channel.
 *
 * Parameters:
 *    cd   - the descriptor of the channel to send to.
 *    send - a pointer to the data to send.
 *
 * Returns:
 *    On success, it returns the descriptor of the channel where the data was sent.
 *    If the operation was not successful, it returns -1.
 */
extern int send_chan(int cd, any_t *send);
    

/*
 * Function: recv_chan
 * -------------------
 * This function receives data from a channel.
 *
 * Parameters:
 *    cd   - the descriptor of the channel to receive from.
 *    recv - a pointer to a location where the received data should be stored.
 *
 * Returns:
 *    On success, it returns the descriptor of the channel from which the data was received.
 *    If the operation was not successful, it returns -1.
 */
extern int recv_chan(int cd, any_t *recv);

extern void dump_channel(int cd);
int select_chan(select_set_t *set, size_t n, int should_block);
#endif