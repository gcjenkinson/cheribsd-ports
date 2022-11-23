--- gio/gdbuserror.c.orig	2022-11-23 15:19:08.624344000 +0000
+++ gio/gdbuserror.c	2022-11-23 15:37:26.256308000 +0000
@@ -160,7 +160,7 @@
 g_dbus_error_quark (void)
 {
   G_STATIC_ASSERT (G_N_ELEMENTS (g_dbus_error_entries) - 1 == G_DBUS_ERROR_PROPERTY_READ_ONLY);
-  static gsize quark = 0;
+  static gintptr quark = 0;
   g_dbus_error_register_error_domain ("g-dbus-error-quark",
                                       &quark,
                                       g_dbus_error_entries,
@@ -184,11 +184,11 @@
  */
 void
 g_dbus_error_register_error_domain (const gchar           *error_domain_quark_name,
-                                    volatile gsize        *quark_volatile,
+                                    volatile gintptr	  *quark_volatile,
                                     const GDBusErrorEntry *entries,
                                     guint                  num_entries)
 {
-  gsize *quark;
+  gintptr *quark;
 
   g_return_if_fail (error_domain_quark_name != NULL);
   g_return_if_fail (quark_volatile != NULL);
@@ -197,7 +197,7 @@
 
   /* Drop the volatile qualifier, which should never have been on the argument
    * in the first place. */
-  quark = (gsize *) quark_volatile;
+  quark = (gintptr *) quark_volatile;
 
   if (g_once_init_enter (quark))
     {
