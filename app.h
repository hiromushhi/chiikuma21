#ifndef CHIIKUMA21_APP_H_
#define CHIIKUMA21_APP_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef STACK_SIZE
#define STACK_SIZE 4096
#endif

void main_task();
void exec_action_task();
void update_info_task();

#ifdef __cplusplus
}
#endif

#endif  // CHIIKUMA21_APP_H_
