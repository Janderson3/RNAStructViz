#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Tabs.H>

class GraphWindow : public Fl_Window
{ 
public:
    
    struct TestStruct
    {
        char *name;
        int basePairs;
        int falsePositives;
        int truePositives;
        bool referenceStruct;
    };
    
	//GraphWindow(int w, int h, const char *label, int* mydata);
    GraphWindow(int w, int h, const char *label);

protected:
	void draw();
    
private:
	void DrawGraph();
    void DrawGraphLabels();
    void DrawTab(int sel);
	int data[3];
	int width;
	int height;
    int selectedTab;
    int splitGraph;
    int graphX;
    int graphY;
    TestStruct* t_structs;
    Fl_Group *group[2];
    Fl_Tabs *tabs;
};

#endif //GRAPHWINDOW_H