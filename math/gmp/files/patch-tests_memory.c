--- tests/memory.c.orig	2022-11-16 14:13:51.451776000 +0000
+++ tests/memory.c	2022-11-15 18:16:41.820653000 +0000
@@ -93,10 +93,10 @@
   h->next = tests_memory_list;
   tests_memory_list = h;
 
-  rptr = __gmp_default_allocate (size + 2 * sizeof (mp_limb_t));
-  ptr = (void *) ((gmp_intptr_t) rptr + sizeof (mp_limb_t));
+  rptr = __gmp_default_allocate (size + 2 * ROUND_UP_MULTIPLE(sizeof (mp_limb_t), __TMP_ALIGN));
+  ptr = (void *) ((gmp_intptr_t) rptr + ROUND_UP_MULTIPLE(sizeof (mp_limb_t), __TMP_ALIGN));
 
-  *((mp_limb_t *) ((gmp_intptr_t) ptr - sizeof (mp_limb_t)))
+  *((mp_limb_t *) ((gmp_intptr_t) ptr - ROUND_UP_MULTIPLE(sizeof (mp_limb_t), __TMP_ALIGN)))
     = PATTERN1 - PTRLIMB (ptr);
   PATTERN2_var = PATTERN2 - PTRLIMB (ptr);
   memcpy ((void *) ((gmp_intptr_t) ptr + size), &PATTERN2_var, sizeof (mp_limb_t));
@@ -136,7 +136,7 @@
       abort ();
     }
 
-  if (*((mp_limb_t *) ((gmp_intptr_t) ptr - sizeof (mp_limb_t)))
+  if (*((mp_limb_t *) ((gmp_intptr_t) ptr - ROUND_UP_MULTIPLE(sizeof (mp_limb_t), __TMP_ALIGN)))
       != PATTERN1 - PTRLIMB (ptr))
     {
       fprintf (stderr, "in realloc: redzone clobbered before block\n");
@@ -149,12 +149,12 @@
       abort ();
     }
 
-  rptr = __gmp_default_reallocate ((void *) ((gmp_intptr_t) ptr - sizeof (mp_limb_t)),
-				 old_size + 2 * sizeof (mp_limb_t),
-				 new_size + 2 * sizeof (mp_limb_t));
-  ptr = (void *) ((gmp_intptr_t) rptr + sizeof (mp_limb_t));
+  rptr = __gmp_default_reallocate ((void *) ((gmp_intptr_t) ptr - ROUND_UP_MULTIPLE(sizeof (mp_limb_t), __TMP_ALIGN)),
+				 old_size + 2 * ROUND_UP_MULTIPLE(sizeof (mp_limb_t), __TMP_ALIGN),
+				 new_size + 2 * ROUND_UP_MULTIPLE(sizeof (mp_limb_t), __TMP_ALIGN));
+  ptr = (void *) ((gmp_intptr_t) rptr + ROUND_UP_MULTIPLE(sizeof (mp_limb_t), __TMP_ALIGN));
 
-  *((mp_limb_t *) ((gmp_intptr_t) ptr - sizeof (mp_limb_t)))
+  *((mp_limb_t *) ((gmp_intptr_t) ptr - ROUND_UP_MULTIPLE(sizeof (mp_limb_t), __TMP_ALIGN)))
     = PATTERN1 - PTRLIMB (ptr);
   PATTERN2_var = PATTERN2 - PTRLIMB (ptr);
   memcpy ((void *) ((gmp_intptr_t) ptr + new_size), &PATTERN2_var, sizeof (mp_limb_t));
@@ -186,7 +186,7 @@
 
   *hp = h->next;  /* unlink */
 
-  if (*((mp_limb_t *) ((gmp_intptr_t) ptr - sizeof (mp_limb_t)))
+  if (*((mp_limb_t *) ((gmp_intptr_t) ptr - ROUND_UP_MULTIPLE(sizeof (mp_limb_t), __TMP_ALIGN)))
       != PATTERN1 - PTRLIMB (ptr))
     {
       fprintf (stderr, "in free: redzone clobbered before block\n");
@@ -199,8 +199,8 @@
       abort ();
     }
 
-  __gmp_default_free ((void *) ((gmp_intptr_t) ptr - sizeof(mp_limb_t)),
-		      h->size + 2 * sizeof (mp_limb_t));
+  __gmp_default_free ((void *) ((gmp_intptr_t) ptr - ROUND_UP_MULTIPLE(sizeof(mp_limb_t), __TMP_ALIGN)),
+		      h->size + ROUND_UP_MULTIPLE(2 * sizeof (mp_limb_t), __TMP_ALIGN));
   __gmp_default_free (h, sizeof (*h));
 }
 
