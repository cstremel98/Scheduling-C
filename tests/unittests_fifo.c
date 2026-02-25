// 1
Test(Fifo, e0) {
  PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);

  PROCESS *selected = fifo_process_selector(pl);
  cr_assert(selected == p0);
}
/*
// 2
Test(Fifo, e0_e1) {
  PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS *p1 = create_process(1.0f, 0.0f, 1.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);

  PROCESS *selected = fifo_process_selector(pl);

  cr_assert(selected == p0);
  cr_assert(selected != p1);
  cr_assert(selected != NULL);
}

// 3
Test(Fifo, e1_e0) {
  PROCESS *p0 = create_process(1.0f, 0.0f, 1.0f);
  PROCESS *p1 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);

  PROCESS *selected = fifo_process_selector(pl);

  cr_assert(selected == p1);
}

// 4
Test(Fifo, e0_e1_1) {
  PROCESS *p0 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS *p1 = create_process(1.0f, 0.0f, 1.0f);
  PROCESS *p2 = create_process(1.0f, 0.0f, 1.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);
  add_process_to_tail(pl, p2);

  PROCESS *selected = fifo_process_selector(pl);
  cr_assert(selected == p0);
}

// 5
Test(Fifo, e1_e0_e1) {
  PROCESS *p0 = create_process(1.0f, 0.0f, 1.0f);
  PROCESS *p1 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS *p2 = create_process(1.0f, 0.0f, 1.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);
  add_process_to_tail(pl, p2);

  PROCESS *selected = fifo_process_selector(pl);
  cr_assert(selected == p1);
}

// 5
Test(Fifo, e1_e1_e0) {
  PROCESS *p0 = create_process(1.0f, 0.0f, 1.0f);
  PROCESS *p1 = create_process(1.0f, 0.0f, 1.0f);
  PROCESS *p2 = create_process(1.0f, 0.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);
  add_process_to_tail(pl, p2);

  PROCESS *selected = fifo_process_selector(pl);
  cr_assert(selected == p2);
}

// 6
Test(Fifo, tie_breaking_same_arrival_time) {
  PROCESS *p0 = create_process(1.0f, 0.0f, 5.0f);
  PROCESS *p1 = create_process(2.0f, 0.0f, 5.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);
  add_process_to_tail(pl, p1);

  PROCESS *selected = fifo_process_selector(pl);
  cr_assert(selected == p0);
}

// 7
Test(Fifo, single_process_zero_duration) {
  PROCESS *p0 = create_process(0.0f, 0.0f, 0.0f);
  PROCESS_LIST *pl = create_process_list();
  add_process_to_tail(pl, p0);

  PROCESS *selected = fifo_process_selector(pl);
  cr_assert(selected == p0);
  cr_assert(p0->duration == 0.0f);
}*/
