PORTNAME=	kwin
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-wm kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 window manager
WWW=		https://www.kde.org/plasma-desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libXcursor.so:x11/libXcursor \
		libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libepoll-shim.so:devel/libepoll-shim \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinput.so:x11/libinput \
		libudev.so:devel/libudev-devd \
		liblcms2.so:graphics/lcms2 \
		libwayland-cursor.so:graphics/wayland \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxkbcommon.so:x11/libxkbcommon
BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

CONFLICTS_INSTALL=	kwinft # bin/kwin_wayland

USES=		cmake compiler:c++11-lib gettext gl kde:5 pkgconfig \
		qt:5 shebangfix tar:xz xorg
USE_GL=		egl gbm
USE_GNOME=	glib20
USE_KDE=	activities attica auth breeze codecs completion config \
		configwidgets coreaddons crash dbusaddons decoration globalaccel i18n \
		iconthemes idletime init jobwidgets kcmutils kdeclarative kio \
		kscreenlocker kwayland-integration kwayland-server newstuff \
		notifications package plasma-framework \
		plasma-wayland-protocols runner service sonnet textwidgets \
		wayland widgetsaddons windowsystem xmlgui \
		ecm:build
USE_LDCONFIG=	yes
USE_QT=		concurrent core dbus declarative gui network \
		sensors uiplugin uitools widgets x11extras xml \
		buildtools:build qmake:build testlib:build \
		quickcontrols2:run virtualkeyboard:run
USE_XORG=	ice sm x11 xcb xext xi
SHEBANG_FILES=	kconf_update/*.py \
		kconf_update/*.pl

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes

.include <bsd.port.pre.mk>

.if !${ABI:Mpurecap}
BUILD_DEPENDS+=	xwayland-devel>0:x11-servers/xwayland-devel
RUN_DEPENDS+=	xwayland-devel>0:x11-servers/xwayland-devel
USES+=		gnome python:3.7+,run
USE_QT+=	multimedia script
.endif

.include <bsd.port.post.mk>
