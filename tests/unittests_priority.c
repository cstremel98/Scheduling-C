Test(Priority, pri0) {
  PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);

  PROCESS *selected = priority_process_selector(pl);
  cr_assert(selected == p0);
}

Test(Priority, pri0_pri1) {
  PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS *p1 = create_process(1.0f, 1.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);

  PROCESS *selected = priority_process_selector(pl);
  cr_assert(selected == p0);
}

Test(Priority, pri1_pri0) {
  PROCESS *p0 = create_process(1.0f, 1.0f, 0.0f);
  PROCESS *p1 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);

  PROCESS *selected = priority_process_selector(pl);
  cr_assert(selected == p1);
}

Test(Priority, pri0_pri1_pri1) {
  PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS *p1 = create_process(1.0f, 1.0f, 0.0f);
  PROCESS *p2 = create_process(1.0f, 1.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);
  add_process_to_tail(pl, p2);

  PROCESS *selected = priority_process_selector(pl);
  cr_assert(selected == p0);
}

Test(Priority, pri1_pri0_pri1) {
  PROCESS *p0 = create_process(1.0f, 1.0f, 0.0f);
  PROCESS *p1 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS *p2 = create_process(1.0f, 1.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);
  add_process_to_tail(pl, p2);

  PROCESS *selected = priority_process_selector(pl);
  cr_assert(selected == p1);
}

Test(Priority, pri1_pri1_pri0) {
  PROCESS *p0 = create_process(1.0f, 1.0f, 0.0f);
  PROCESS *p1 = create_process(1.0f, 1.0f, 0.0f);
  PROCESS *p2 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);
  add_process_to_tail(pl, p2);

  PROCESS *selected = priority_process_selector(pl);
  cr_assert(selected == p2);
}

Test(Priority, tie_breaking_same_priority) {
  PROCESS *p0 = create_process(1.0f, 1.0f, 0.0f);
  PROCESS *p1 = create_process(1.0f, 1.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);

  PROCESS *selected = priority_process_selector(pl);
  cr_assert(selected == p0);
}
Test(Priority, priority_comparison_explanation) {
  PROCESS *high_priority = create_process(1.0f, 0.0f, 0.0f);
  PROCESS *low_priority = create_process(1.0f, 1.0f, 0.0f);
  
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, low_priority);
  add_process_to_tail(pl, high_priority);
  
  PROCESS *selected = priority_process_selector(pl);
  
  cr_assert(selected == high_priority);
  cr_assert(selected->priority == 0.0f);
}

Test(Priority, empty_process_list) {
  PROCESS_LIST *empty_pl = create_process_list();
  
  PROCESS *selected = priority_process_selector(empty_pl);
  cr_assert(selected == NULL);
}
