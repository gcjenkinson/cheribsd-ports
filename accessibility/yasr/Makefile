PORTNAME=	yasr
PORTVERSION=	0.6.9
PORTREVISION=	5
CATEGORIES=	accessibility
MASTER_SITES=	SF

MAINTAINER=	David.K.Gerry@GMail.com
COMMENT=	General-purpose console screen reader
WWW=		http://yasr.sourceforge.net/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase
GNU_CONFIGURE=	yes
PORTDOCS=	AUTHORS BUGS CREDITS ChangeLog NEWS README TODO \
		README-br README-de README-es README-fr README-ru
SUB_FILES=	pkg-message

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

PLIST_FILES=	bin/yasr \
		man/man1/yasr.1.gz \
		%%DATADIR%%/yasr.conf \
		%%NLS%%share/locale/es/LC_MESSAGES/yasr.mo \
		%%NLS%%share/locale/fr/LC_MESSAGES/yasr.mo

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
