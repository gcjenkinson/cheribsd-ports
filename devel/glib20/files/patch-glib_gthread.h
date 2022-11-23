--- glib/gthread.h.orig	2022-11-22 16:43:37.842509000 +0000
+++ glib/gthread.h	2022-11-22 17:22:52.811417000 +0000
@@ -232,7 +232,7 @@
 gboolean        g_once_init_enter               (volatile void  *location);
 GLIB_AVAILABLE_IN_ALL
 void            g_once_init_leave               (volatile void  *location,
-                                                 gsize           result);
+                                                 gpointer result);
 
 /* Use C11-style atomic extensions to check the fast path for status=ready. If
  * they are not available, fall back to using a mutex and condition variable in
@@ -264,7 +264,7 @@
   (G_GNUC_EXTENSION ({                                               \
     G_STATIC_ASSERT (sizeof *(location) == sizeof (gpointer));       \
     0 ? (void) (*(location) = (result)) : (void) 0;                  \
-    g_once_init_leave ((location), (gsize) (result));                \
+    g_once_init_leave ((location), (gpointer) (result));                \
   }))
 #else
 # define g_once_init_enter(location) \
