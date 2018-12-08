po: index.po

english: index.en.md

%.en.md: %.po %.cn.md
	po4a-translate -M UTF-8 -f text -o markdown -m $(@:%.en.md=%.cn.md) -p $< -l $@

%.po: %.cn.md
	po4a-gettextize -M UTF-8 -f text -m $< -p $@


