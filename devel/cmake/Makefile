PORTNAME=	cmake
DISTVERSION=	3.24.0
CATEGORIES=	devel

BROKEN_purecap=	requires missing CheriABI Python
USE_PKG64=	1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Meta-port to connect all CMake bits
WWW=		https://www.cmake.org/

LICENSE=	BSD3CLAUSE

USES=		cmake:run metaport

NO_LICENSES_INSTALL=	yes
PLIST_FILES=	# not applicable

OPTIONS_DEFINE=	DOCS GUI MANPAGES
OPTIONS_DEFAULT=	MANPAGES

GUI_DESC=		Qt-based GUI

DOCS_RUN_DEPENDS=	${LOCALBASE}/share/doc/cmake/html/index.html:devel/cmake-doc
GUI_RUN_DEPENDS=	${LOCALBASE}/bin/cmake-gui:devel/cmake-gui
MANPAGES_RUN_DEPENDS=	${LOCALBASE}/man/man1/cmake.1.gz:devel/cmake-man

# Mk/Uses/cmake.mk sets do-configure which we don't want for a meta-port
do-configure:

.include <bsd.port.mk>
