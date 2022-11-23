--- glib/gatomic.h.orig	2022-11-22 14:12:25.785147000 +0000
+++ glib/gatomic.h	2022-11-22 14:11:04.057400000 +0000
@@ -234,7 +234,7 @@
   (G_GNUC_EXTENSION ({                                                       \
     gsize *gapa_atomic = (gsize *) (atomic);                                 \
     G_STATIC_ASSERT (sizeof *(atomic) == sizeof (gpointer));                 \
-    G_STATIC_ASSERT (sizeof *(atomic) == sizeof (gsize));                    \
+    G_STATIC_ASSERT (sizeof *(atomic) == sizeof (gintptr));                    \
     (void) (0 ? (gpointer) *(atomic) : NULL);                                \
     (void) (0 ? (val) ^ (val) : 1);                                          \
     (gsize) __atomic_fetch_and (gapa_atomic, (val), __ATOMIC_SEQ_CST);       \
@@ -243,7 +243,7 @@
   (G_GNUC_EXTENSION ({                                                       \
     gsize *gapo_atomic = (gsize *) (atomic);                                 \
     G_STATIC_ASSERT (sizeof *(atomic) == sizeof (gpointer));                 \
-    G_STATIC_ASSERT (sizeof *(atomic) == sizeof (gsize));                    \
+    G_STATIC_ASSERT (sizeof *(atomic) == sizeof (gintptr));                    \
     (void) (0 ? (gpointer) *(atomic) : NULL);                                \
     (void) (0 ? (val) ^ (val) : 1);                                          \
     (gsize) __atomic_fetch_or (gapo_atomic, (val), __ATOMIC_SEQ_CST);        \
@@ -252,7 +252,7 @@
   (G_GNUC_EXTENSION ({                                                       \
     gsize *gapx_atomic = (gsize *) (atomic);                                 \
     G_STATIC_ASSERT (sizeof *(atomic) == sizeof (gpointer));                 \
-    G_STATIC_ASSERT (sizeof *(atomic) == sizeof (gsize));                    \
+    G_STATIC_ASSERT (sizeof *(atomic) == sizeof (gintptr));                    \
     (void) (0 ? (gpointer) *(atomic) : NULL);                                \
     (void) (0 ? (val) ^ (val) : 1);                                          \
     (gsize) __atomic_fetch_xor (gapx_atomic, (val), __ATOMIC_SEQ_CST);       \
