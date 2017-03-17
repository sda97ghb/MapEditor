CONFIG += c++11

TEMPLATE = subdirs

SUBDIRS = MapEditor SFMLWidgets TinyXml2
#SUBDIRS = MapEditor SFMLWidgets

MapEditor.depends = SFMLWidgets TinyXml2
#MapEditor.depends = SFMLWidgets
