--- gio/gdbuserror.h.orig	2022-11-23 15:41:06.514384000 +0000
+++ gio/gdbuserror.h	2022-11-23 15:40:28.690693000 +0000
@@ -81,7 +81,7 @@
                                              const gchar           *dbus_error_name);
 GLIB_AVAILABLE_IN_ALL
 void     g_dbus_error_register_error_domain (const gchar           *error_domain_quark_name,
-                                             volatile gsize        *quark_volatile,
+                                             volatile gintptr      *quark_volatile,
                                              const GDBusErrorEntry *entries,
                                              guint                  num_entries);
 
