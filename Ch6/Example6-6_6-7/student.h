#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
//start id="student"
class Student  {
 public:
    Student(QString nm, long id, QString major, int year = 1);
    /*In general, if a class has one or more virtual functions, it should also have a virtual
destructor. This is because when operating on a collection of polymorphic objects, it is common
to delete objects through base class pointers, which results in an indirect call to the destructor.
If the destructor is not virtual, compile-time binding determines which destructor is called and
may result in incomplete destruction of the derived object.*/
    virtual ~Student() {}                /* We added the keyword virtual here. */
    virtual QString getClassName() const;/* We added virtual here also. */
     QString toString() const;            /* This should also be virtual.*/
 private:
    QString m_Name;
    QString m_Major;
    long m_StudentId;
 protected:
    int m_Year;
    QString yearStr() const;
};
//end
class Undergrad: public Student {
 public:
    Undergrad(QString name, long id, QString major, int year, int sat);
    QString getClassName() const;
    QString toString() const;
 private:
    int m_SAT;                           /* Scholastic Aptitude Test score total */

};

class GradStudent : public Student {
 public:
    enum Support { ta, ra, fellowship, other };
    GradStudent(QString nm, long id, QString major,
                int yr, Support support);

    QString getClassName() const ;
    QString toString() const;
 protected:
    static QString supportStr(Support sup) ;
 private:
    Support  m_Support;
};

#endif        //  #ifndef STUDENT_H
