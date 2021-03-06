
#ifndef DIALOG_REPLACE_H_
#define DIALOG_REPLACE_H_

#include "Dialog.h"
#include "Direction.h"
#include "SearchType.h"
#include "ui_DialogReplace.h"
#include <QPointer>

class DialogMultiReplace;
class DocumentWidget;
class MainWindow;

class DialogReplace : public Dialog {
	Q_OBJECT
public:
    DialogReplace(MainWindow *window, DocumentWidget *document, Qt::WindowFlags f = Qt::WindowFlags());
    ~DialogReplace() override = default;
	
protected:
	void keyPressEvent(QKeyEvent *event) override;
	void showEvent(QShowEvent *event) override;
	
public:
    void setDocument(DocumentWidget *document);
    void setTextField(DocumentWidget *document);
	void initToggleButtons(SearchType searchType);
	void fUpdateActionButtons();
	void rSetActionButtons(bool replaceBtn, bool replaceFindBtn, bool replaceAndFindBtn, bool replaceInWinBtn, bool replaceInSelBtn, bool replaceAllBtn);
	void UpdateReplaceActionButtons();
    bool getReplaceDlogInfo(Direction *direction, QString *searchString, QString *replaceString, SearchType *searchType);
	void collectWritableWindows();

public:
	bool keepDialog() const;

private Q_SLOTS:
	void on_checkBackward_toggled(bool checked);
	void on_checkRegex_toggled(bool checked);
	void on_checkCase_toggled(bool checked);
	void on_checkKeep_toggled(bool checked);
	void on_textFind_textChanged(const QString &text);
	void on_buttonFind_clicked();
	void on_buttonReplace_clicked();
	void on_buttonReplaceFind_clicked();
	void on_buttonWindow_clicked();
	void on_buttonSelection_clicked();
	void on_buttonMulti_clicked();
	
public:
    MainWindow *window_;
    DocumentWidget *document_;

    // temporary list of writable documents, used during multi-file replacements
    std::vector<DocumentWidget *> writableWindows_;
	Ui::DialogReplace ui;
	bool lastRegexCase_;        /* idem, for regex mode in find dialog */
	bool lastLiteralCase_;      /* idem, for literal mode */
	QPointer<DialogMultiReplace> dialogMultiReplace_;	
};

#endif
