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

    template <typename T>
    class gt_HashItem
    {
    public:
        gt_HashItem(): Next(NULL), Key(""), Value(NULL) {}
        ~gt_HashItem() { delete Next; delete Value; }
    
        /* data */
        gt_HashItem<T> *Next;
        Gt_String Key;
        T* Value;
    };

    template <typename T>
    class gt_HashList
    {
    public:
        gt_HashList(Gt_uint32_t Size = 65536)
        {
            arraySize = Size;
            enumIndex = 0;
            currItem = NULL;
            Buckets.resize(Size, NULL);
        }
        ~gt_HashList()
        {
            Clear();
        }
        void Add(const Gt_String& Key, T *Value)
        {
            int hash = HashOf(Key) % arraySize;
            gt_HashItem<T> *bucket = new gt_HashItem<T>();
            bucket->Key = Key;
            bucket->Value = Value;
            bucket->Next = Buckets[hash];
            Buckets[hash] = bucket;
        }
        void Clear()
        {
            for (Gt_uint32_t i = 0; i < arraySize; ++i)
            {
                gt_HashItem<T> *n, *p = Buckets[i];
                while (p)
                {
                    n = p->Next;
                    delete p;
                    p = NULL;
                    p = n;
                }
                Buckets[i] = NULL;
            }
        }
        void Remove(const Gt_String& Key)
        {
            gt_HashItem<T> **P = Find(Key);
            gt_HashItem<T> *n = *p;
            if (n != NULL)
            {
                *p = n->Next;
                delete n;
                n = NULL;
            }
        }
        bool Modify(const Gt_String& Key, T *Value)
        {
            gt_HashItem<T> *p = *(Find(Key));
            if (p)
            {
                p->Value = Value;
                return true;
            }
            else
                return false;
        }
        T* ValueOf(const Gt_String& Key)
        {
            gt_HashItem<T> *p = *(Find(Key));
            if (p)
                return p->Value;
            else
                return NULL;
        }
        bool FindKey(const Gt_String& Key)
        {
            gt_HashItem<T> *p = *(Find(Key));
            return p != NULL;
        }
        void StartEnum()
        {
            enumIndex = 0;
            currItem = NULL;
        }
        bool EnumValue(T& Value)
        {
            bool result = false;
            while (currItem != NULL)
            {
                currItem = currItem->Next;
                break;
            }
            while (currItem == NULL && EnumIndex < ArraySize)
            {
                currItem = Buckets[EnumIndex];
                ++EnumIndex;
            }
            if (currItem != NULL)
            {
                Value = *(currItem->Value);
                result = true;
            }
            return result;
        }
    protected:
        virtual Gt_uint32_t HashOf(const Gt_String& Key)
        {
            Gt_uint32_t result = 0;
            for (int i = 0; i < Key.length(); ++i)
                result = (((result << 2) | (result >> (sizeof(result) * 8  - 2))) ^ int(Key[i]));
            return result;
        }
        gt_HashItem<T>** Find(const Gt_String& Key)
        {
            gt_HashItem<T> **p = &Buckets[HashOf(Key) % arraySize];
            while (*p != NULL)
            {
                if ((*p)->Key == Key)
                    break;
                else
                    p = &((*p)->Next);
            }
            return p;
        }
    private:
        Gt_uint32_t arraySize;
        Gt_uint32_t enumIndex;
        gt_HashItem<T> *currItem;
        vector<gt_HashItem<T>*> Buckets;
    };
};

#endif
