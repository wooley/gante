#ifndef GT_GANTE_INCLUDED
#define GT_GANTE_INCLUDED

#include "gt_config.h"
#include "gt_FactoryCalendar.h"

namespace GtGante {

    template <typename T>
    class gt_Task
    {
    private:
        long            m_Id;
        Gt_uint64_t     m_BeginTime;
        Gt_uint64_t     m_FinishTime;
        Gt_uint64_t     m_Duration;	
        Gt_String       m_Equipment;

        long            m_Prior;
        T*              Data;

        bool            isLeaf;
    public:
        gt_Task(void);
        ~gt_Task();

        void setId(long Id);
    };

    class gt_BiTree;
    typedef gt_BiTree gt_TreeNode;
    typedef gt_BiTree gt_TreeRoot;

    template <typename T>
    class gt_BiTree
    {
    private:
        T* m_t;
        gt_TreeNode* Node;
    public:
        gt_BiTree(void);
        ~gt_BiTree();

        gt_TreeNode* AddLeftNode();
        gt_TreeNode* AddRightNode();

        bool Sort();
    };

    class gt_Gante
    {
    private:
        long                    m_Id;
        gt_BiTree<gt_Task*>     TaskRoot; 
        std::map<int, gt_Task*> mTasks;
        std::vector<gt_Task*>   vTasks;
        gt_FactoryCalendar*     fc; 
    public:
        gt_Gante(void);
        ~gt_Gante();

        long generateId();          // create Id

        bool setFactoryCalendar(gt_FactoryCalendar* factoryCalendar);  // 设置工厂日历

        gt_Task* getTask(long Id);  // 

        gt_Task* addTask(void);
        gt_Task* addTask(long Prior);

        bool deleteTask(long Id);
        bool deleteTask(gt_Task* task);

        bool upGrade(long Id);      // 升级
        bool downGrade(long Id);    // 降级

        void update(void);	

        bool Clear(void);
    };
};

#endif
