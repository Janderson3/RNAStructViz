/*
    The window that computes the stats of a folder.
 */

#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include <vector>

class StatsWindow : public Fl_Window
{
public:
    StatsWindow(int wid, int hgt, const char *label, int folderIndex);
    virtual ~StatsWindow();
    
    //Manages structures
    void AddStructure(const char* filename, const int index);
    void RemoveStructure(const int index);
    void SetStructures(int folderIndex);
    
    /*
     Set the reference structure.
     
     Giving an index of -1 clears the reference structure.
     */
    void SetReferenceStructure(const int index);
    
    /*
    An index of -1 means there is no reference structure.
    */
    inline int GetReferenceStructure()
    {
        return m_referenceIndex;
    }

private:
    /*
     Callback to make a structure the reference.
     */
    static void ReferenceCallback(Fl_Widget* widget, void* userData);

    void ClearTruthValues();
    void UpdateTruthValues();
    
    Fl_Scroll *statsScroll;
    Fl_Pack *statsPack;
        
    // Index of the folder
    int m_folderIndex;
    
    // Index of the reference sequence. Can be -1 for no sequence. 
    int referenceIndex;
};

#end if