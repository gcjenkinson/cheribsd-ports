PORTNAME=	plasma-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Platform Theme integration plugins for the Plasma workspaces
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig qt:5 \
		shebangfix tar:xz xorg
USE_KDE=	auth bookmarks breeze codecs completion config configwidgets \
		coreaddons ecm i18n iconthemes itemviews jobwidgets kio \
		notifications service solid wayland widgetsaddons windowsystem \
		xmlgui \
		qqc2-desktop-style:run
USE_QT=		concurrent core dbus declarative gui network quickcontrols2 \
		widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	x11 xcb xcursor

SHEBANG_FILES=	src/platformtheme/fonts_akregator.pl \
		src/platformtheme/fonts_global.pl \
		src/platformtheme/fonts_kate.pl \
		src/platformtheme/mono_font.pl

OPTIONS_SINGLE=	NOTO
OPTIONS_SINGLE_NOTO=	LIGHT BIG
OPTIONS_DEFAULT=	LIGHT
NOTO_DESC=	KDE default font
LIGHT_DESC=	Use noto-light
BIG_DESC=	Use complete noto

LIGHT_RUN_DEPENDS=	noto-basic>=0:x11-fonts/noto-basic
BIG_RUN_DEPENDS=	noto>=0:x11-fonts/noto

OPTIONS_EXCLUDE_purecap=	LIGHT BIG

.include <bsd.port.pre.mk>

.if !${ABI:Mpurecap}
RUN_DEPENDS=	hack-font>=0:x11-fonts/hack-font
.endif

.include <bsd.port.post.mk>
