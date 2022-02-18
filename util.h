#ifndef UTIL_H_
#define UTIL_H_

#define __join(l, r) l##r
#define __uvar __join(__macro_var_, __LINE__)

#define wrap(start, end)                                                       \
  for (int __uvar = ((start), 0); __uvar != 1; (end), __uvar++)

#define with(var, start, end)                                                  \
  var;                                                                         \
  wrap(start, end)

#define dummy(parent_struct) ((parent_struct *)0)

#define sizeof_member(parent_struct, member_name)                              \
  sizeof(dummy(parent_struct)->member_name)

#define container_of(ptr, type, member)                                        \
  ((type *)_p_container_of(ptr, dummy(type), member))
#define _p_container_of(o, p, m) ((char *)o - ((char *)&p->m))

struct vec {
  int x;
  int y;
};

#endif // UTIL_H_
