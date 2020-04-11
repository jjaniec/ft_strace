/*
** Important note:
** All user generated si codes are negatives,
** to keep the same usage as with kernel signals
** the indexes of the arrays are negated to be positive
** The real values of the codes are < 0,
** so SI_ASYNCNL is in reality == -60
*/

[ 60] = "SI_ASYNCNL", /* Sent by asynch name lookup completion.  */
[  6] = "SI_TKILL", /* Sent by tkill.  */
[  5] = "SI_SIGIO", /* Sent by queued SIGIO. */
[  4] = "SI_ASYNCIO", /* Sent by AIO completion.  */
[  3] = "SI_MESGQ", /* Sent by real time mesq state change.  */
[  2] = "SI_TIMER", /* Sent by timer expiration.  */
[  1] = "SI_QUEUE", /* Sent by sigqueue.  */
[  0] = "SI_USER" /* Sent by kill, sigsend, raise.  */
