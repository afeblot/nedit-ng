cmake_minimum_required(VERSION 3.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

find_package(Qt5 5.4.0 REQUIRED Widgets Network Xml PrintSupport)
find_package(Boost 1.35 REQUIRED)

qt5_add_resources(QRC_SOURCES
	nedit.qrc
)

qt5_wrap_cpp(MOC_SOURCES
	FixedFontSelector.h
	ElidedLabel.h
	CallTipWidget.h
	CommandRecorder.h
	Dialog.h
	DialogAbout.h
	DialogColors.h
	DialogDrawingStyles.h
	DialogDuplicateTags.h
	DialogExecuteCommand.h
	DialogFilter.h
	DialogFind.h
	DialogFonts.h
	DialogLanguageModes.h
	DialogMacros.h
	DialogMoveDocument.h
	DialogMultiReplace.h
	DialogOutput.h
	DialogPrint.h
	DialogPrompt.h
	DialogPromptList.h
	DialogPromptString.h
	DialogRepeat.h
	DialogReplace.h
	DialogShellMenu.h
	DialogSmartIndent.h
	DialogSmartIndentCommon.h
	DialogSyntaxPatterns.h
	DialogTabs.h
	DialogWindowBackgroundMenu.h
	DialogWindowSize.h
	DialogWindowTitle.h
	DialogWrapMargin.h
	DocumentModel.h
	DocumentWidget.h
	HighlightPatternModel.h
	HighlightStyleModel.h
	KeySequenceEdit.h
	LanguageModeModel.h
	MainWindow.h
	MenuItemModel.h
	NeditServer.h
	TabWidget.h
	TextArea.h
)

qt5_wrap_ui(UIC_SOURCES
	FixedFontSelector.ui
	CallTipWidget.ui
	DialogAbout.ui
	DialogColors.ui
	DialogDrawingStyles.ui
	DialogDuplicateTags.ui
	DialogExecuteCommand.ui
	DialogFilter.ui
	DialogFind.ui
	DialogFonts.ui
	DialogLanguageModes.ui
	DialogMacros.ui
	DialogMoveDocument.ui
	DialogMultiReplace.ui
	DialogOutput.ui
	DialogPrint.ui
	DialogPromptList.ui
	DialogPromptString.ui
	DialogPrompt.ui
	DialogRepeat.ui
	DialogReplace.ui
	DialogShellMenu.ui
	DialogSmartIndentCommon.ui
	DialogSmartIndent.ui
	DialogSyntaxPatterns.ui
	DialogTabs.ui
	DialogWindowBackgroundMenu.ui
	DialogWindowSize.ui
	DialogWindowTitle.ui
	DialogWrapMargin.ui
	DocumentWidget.ui
	MainWindow.ui
)

add_executable(nedit-ng

	${MOC_SOURCES}
	${QRC_SOURCES}
	${UIC_SOURCES}

	FixedFontSelector.h
	FixedFontSelector.cpp
	ElidedLabel.h
	ElidedLabel.cpp
	gap_buffer.h
	gap_buffer_fwd.h
	gap_buffer_iterator.h
	BlockDragTypes.h
	Bookmark.h
	CallTip.h
	CallTipWidget.cpp
	CallTipWidget.h
	CloseMode.h
	CommandRecorder.cpp
	CommandRecorder.h
	CommandSource.h
	CursorStyles.h
	DialogAbout.cpp
	DialogAbout.h
	DialogColors.cpp
	DialogColors.h
	Dialog.cpp
	DialogDrawingStyles.cpp
	DialogDrawingStyles.h
	DialogDuplicateTags.cpp
	DialogDuplicateTags.h
	DialogExecuteCommand.cpp
	DialogExecuteCommand.h
	DialogFilter.cpp
	DialogFilter.h
	DialogFind.cpp
	DialogFind.h
	DialogFonts.cpp
	DialogFonts.h
	Dialog.h
	DialogLanguageModes.cpp
	DialogLanguageModes.h
	DialogMacros.cpp
	DialogMacros.h
	DialogMoveDocument.cpp
	DialogMoveDocument.h
	DialogMultiReplace.cpp
	DialogMultiReplace.h
	DialogOutput.cpp
	DialogOutput.h
	DialogPrint.cpp
	DialogPrint.h
	DialogPrompt.cpp
	DialogPrompt.h
	DialogPromptList.cpp
	DialogPromptList.h
	DialogPromptString.cpp
	DialogPromptString.h
	DialogRepeat.cpp
	DialogRepeat.h
	DialogReplace.cpp
	DialogReplace.h
	DialogShellMenu.cpp
	DialogShellMenu.h
	DialogSmartIndentCommon.cpp
	DialogSmartIndentCommon.h
	DialogSmartIndent.cpp
	DialogSmartIndent.h
	DialogSyntaxPatterns.cpp
	DialogSyntaxPatterns.h
	DialogTabs.cpp
	DialogTabs.h
	DialogWindowBackgroundMenu.cpp
	DialogWindowBackgroundMenu.h
	DialogWindowSize.cpp
	DialogWindowSize.h
	DialogWindowTitle.cpp
	DialogWindowTitle.h
	DialogWrapMargin.cpp
	DialogWrapMargin.h
	Direction.h
	DocumentModel.cpp
	DocumentModel.h
	DocumentWidget.cpp
	DocumentWidget.h
	DragEndEvent.h
	DragStates.h
	EditFlags.h
	Font.cpp
	Font.h
	FontType.h
	Help.cpp
	Help.h
	highlight.cpp
	HighlightData.h
	highlight.h
	HighlightPattern.cpp
	HighlightPattern.h
	HighlightPatternModel.cpp
	HighlightPatternModel.h
	HighlightStyle.h
	HighlightStyleModel.cpp
	HighlightStyleModel.h
	KeySequenceEdit.cpp
	KeySequenceEdit.h
	LanguageMode.h
	LanguageModeModel.cpp
	LanguageModeModel.h
	LockReasons.h
	macro.cpp
	macro.h
	MainWindow.cpp
	MainWindow.h
	MenuData.h
	MenuItem.h
	MenuItemModel.cpp
	MenuItemModel.h
	MultiClickStates.h
	nedit.cpp
	nedit.h
	NeditServer.cpp
	NeditServer.h
	NewMode.h
	PatternSet.cpp
	PatternSet.h
	preferences.cpp
	preferences.h
	Rangeset.cpp
	Rangeset.h
	RangesetTable.cpp
	RangesetTable.h
	ReparseContext.h
	search.cpp
	search.h
	shift.cpp
	ShiftDirection.h
	shift.h
	SignalBlocker.h
	smartIndent.cpp
	SmartIndentEntry.cpp
	SmartIndentEntry.h
	SmartIndentEvent.h
	smartIndent.h
	Style.h
	StyleTableEntry.h
	TabWidget.cpp
	TabWidget.h
	tags.cpp
	tags.h
	TextArea.cpp
	TextArea.h
	TextBuffer.cpp
	TextBufferFwd.h
	TextBuffer.h
	TextBuffer.tcc
	TextEditEvent.cpp
	TextEditEvent.h
	TextSelection.cpp
	TextSelection.h
	UndoInfo.cpp
	UndoInfo.h
	userCmds.cpp
	userCmds.h	
	Verbosity.h
	WindowHighlightData.cpp
	WindowHighlightData.h
	WindowMenuEvent.cpp
	WindowMenuEvent.h
	WrapMode.h
	X11Colors.cpp
	X11Colors.h
)

target_include_directories (nedit-ng PRIVATE
	${Boost_INCLUDE_DIR}
)

target_link_libraries(nedit-ng LINK_PUBLIC
	Util
	Regex
	Settings
	Interpreter
	GSL
	Qt5::Widgets
	Qt5::Network
	Qt5::Xml
	Qt5::PrintSupport
)

set_property(TARGET nedit-ng PROPERTY CXX_EXTENSIONS OFF)
set_property(TARGET nedit-ng PROPERTY CXX_STANDARD 14)

set_target_properties(nedit-ng
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

install (TARGETS nedit-ng DESTINATION bin)
