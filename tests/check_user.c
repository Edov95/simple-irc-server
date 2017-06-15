#include <check.h>
#include "user.h"
#include <stdio.h>
#include <stdlib.h>

START_TEST(test_user_list){

  User_list* list = NULL;

  printf("%i\n", &list);

  User* u = NULL;

  ck_assert_int_eq(add_user(&list,u),-1);

  // popolo la lista
  for (size_t i = 0; i < 10; i++) {
    u = malloc(sizeof(User));
    u -> id = i;
    ck_assert_int_eq(add_user(&list,u),1);
  }

}END_TEST

Suite * user_suite(void)
{
  Suite *s;
  TCase *tc_core;
  s=suite_create("User_List");

  tc_core=tcase_create("Core");

  tcase_add_test(tc_core, test_user_list);
  suite_add_tcase(s, tc_core);
  return s;
}

int main (void)
{
  int number_failed;
  Suite* s;
  SRunner* sr;

  s = user_suite();
  sr = srunner_create(s);

  srunner_run_all(sr,CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return(number_failed == 0) ? EXIT_SUCCESS :EXIT_FAILURE;
}
