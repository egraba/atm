#ifndef __SCREEN_H__
#define __SCREEN_H__

/* Generic screens */
void display_idle_loop();
int display_out_of_service();
int display_operation_selection();
int display_pin_entry();
int display_receipt_question();
int display_receipt_printing();
int display_please_wait();
int display_card_eject();
int display_thank_you();

/* Error screens */
int display_error(char *error);

/* Withdrawal */
int display_amount_selection();
int display_banknotes_denominations();
int display_banknotes_distribution();
int display_banknotes_and_receipt_distribution();

#endif
