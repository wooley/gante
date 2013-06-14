#ifndef GT_GANTE_INCLUDED
#define GT_GANTE_INCLUDED

#include "gt_config.h"
#include "gt_FactoryCalendar.h"

namespace GtGante {

	class gt_Task
	{
	private:
		long Id;
		Gt_long BeginTime;
		Gt_long FinishTime;
		Gt_long Duration;	
		Gt_String Equipment;

		long Prior;
	public:
		gt_Task(void);
		~gt_Task();
	};

	class gt_BiTree;
	typedef gt_BiTree gt_TreeNode;
	typedef gt_BiTree gt_TreeRoot;

	class gt_BiTree
	{
	private:
		gt_TreeNode* Node;
	public:
		gt_BiTree(void);
		~gt_BiTree();
	};

	class gt_Gante
	{
	private:
		long m_Id;
		gt_BiTree* Holder; 
		gt_FactoryCalendar* fc; 
	public:
		gt_Gante(void);
		~gt_Gante();

		long generateId();   // create Id

		bool setFactoryCalendar(gt_FactoryCalendar* factoryCalendar);  // 设置工厂日历

		gt_Task* getTask(long Id);  // 

		gt_Task* addTask(void);
		gt_Task* addTask(long Prior);
		
		bool deleteTask(long Id);
		bool deleteTask(gt_Task* task);

		bool upGrade(long Id);  // 升级
		bool downGrade(long Id);  // 降级

		void update( void );	
	};
};

#endif
