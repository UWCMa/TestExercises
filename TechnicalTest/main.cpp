#include "VerificationClass.h"

int main(int argc, char **argv)
{
    {    //-------------------------------------SocialNetwork: test cases-------------------------------------
        SocialNetwork network;
        
        User Jeff("Jeff", 44, 1.90);     Jeff.setHobbies({"Tennis", "Dance"}) ;      network.addUser(Jeff);
        User Jeffry("Jeff", 41, 1.74);   Jeffry.setHobbies({"Driving"}) ;            network.addUser(Jeffry);
        User Gven("Gven", 23, 1.6);      Gven.setHobbies({"Dance"}) ;                network.addUser(Gven);
        User Ron("Ron", 15, 1.74);       Ron.setHobbies({"Art","Tennis"}) ;          network.addUser(Ron);
        User Fariha("Fariha", 66, 2.05); Fariha.setHobbies({"Tennis"}) ;             network.addUser(Fariha);
        User Xin("Xin", 43, 1.67);       Xin.setHobbies({"Football"}) ;              network.addUser(Xin);
        User Ken("Ken", 43, 1.56);       Ken.setHobbies({"Trips"}) ;                 network.addUser(Ken);
        User Marry("Marry", 19, 1.60);   Marry.setHobbies({"Art"}) ;                 network.addUser(Marry);
        User Santa("Santa", 56, 1.43);   Santa.setHobbies({"New Year"}) ;            network.addUser(Santa);
        User San("Santa", 56, 1.43);     San.setHobbies({"Football", "Tennis"}) ;    network.addUser(San);
        User Katy("Katy",  44, 2);       Katy.setHobbies({"Tennis"}) ;               network.addUser(Katy);
        User Lin("Lin", 49, 1.87);       Lin.setHobbies({"Dance"}) ;                 network.addUser(Lin);
        User Jon("Jon", 18, 2.01);       Jon.setHobbies({"Tennis"}) ;                network.addUser(Jon);
        User Bruce("Bruce", 17, 1.55);   Bruce.setHobbies({"Fight"}) ;               network.addUser(Bruce);
        User Linny("Lin", 19, 1.8);      Linny.setHobbies({"Horseback riding"}) ;    network.addUser(Linny);
        User Mike("Mike", 19, 1.8);      Mike.setHobbies({"Dance", "Tennis"}) ;      network.addUser(Mike);
        
        VerificationClass test(&network);
        //PASSED cases searchByName
        test.test_searchByName("Santa", std::list<User>{Santa, San});
        test.test_searchByName("Gven",  std::list<User>{Gven});
        //FAILED cases searchByName
        test.test_searchByName("Jon", std::list<User>{Ken});
        test.test_searchByName("Gven",std::list<User>{Bruce});
        //PASSED cases test_searchByAge
        test.test_searchByAge(19, std::list<User>{Marry, Linny, Mike});
        test.test_searchByAge(49, std::list<User>{Lin});
        //FAILED cases test_searchByAge
        test.test_searchByAge(18, std::list<User>{Marry, Linny, Mike});
        test.test_searchByAge(49, std::list<User>{Xin});
        //PASSED cases test_searchByHobbie
        test.test_searchByHobbie("Dance", std::list<User>{Jeff, Gven, Lin, Mike});
        test.test_searchByHobbie("Art", std::list<User>{Ron, Marry});
        //FAILED cases test_searchByHobbie
        test.test_searchByHobbie("Tennis", std::list<User>{Jeff, Gven, Lin, Mike});
        test.test_searchByHobbie("Art", std::list<User>{Bruce});
        //PASSED cases
        test.test_deleteUser(Bruce);
        test.test_deleteUser(Bruce);
        test.test_deleteUser(Santa);
        test.test_deleteUser(Linny);
        test.test_deleteUser(Marry);
        test.test_deleteUser(Jeff);
        test.test_deleteUser(Lin);
    };
    
    {//-------------------------------------StoryBoard: test cases-------------------------------------
        Storyboard storyboard;
        
        Note daily_meeting("Daily meeting", "", {"meeting", "scrum"});
        Note todo("ToDo", "", {"keep in mind"});
        Note demo("Demo", "", {"important", "end of sprint", "result"});
        Note presentation("Demo", "", {"result"});
        Note retrospective("Retrospective", "", {"meeting", "result", "analize"});
        Note backlog("Backlog", "", {"planning", "backlog"});
        Note PI_planning("PI planning", "", {"planning", "meeting"});
        Note blocked("Blocked tasks", "", {"suspended"});
        Note ideas("Ideas", "", {"ideas", "brainstorm"});
        Note weekly_sync("Weekly sync", "", {"meeting", "result"});
        
        daily_meeting.changeText("Time: 10:00(NY time). Invited: XLin, XBai, JBroun");
        todo.changeText("Adaptation of interfaces(Major version 12.3");
        demo.changeText("Prepare learning gas/charging station via Personal assistance");
        retrospective.changeText("Date: 28.05.19");
        PI_planning.changeText("Date: 23.06.19");
        blocked.changeText("Tasks 1413/1414/1415.");
        weekly_sync.changeText("every Friday: 16:00(NY time)");

        storyboard.addNote(daily_meeting);
        storyboard.addNote(todo);
        storyboard.addNote(demo);
        storyboard.addNote(presentation);
        storyboard.addNote(retrospective);
        storyboard.addNote(backlog);
        storyboard.addNote(PI_planning);
        storyboard.addNote(blocked);
        storyboard.addNote(ideas);
        storyboard.addNote(weekly_sync);
        
        VerificationClass test(&storyboard);
        //PASSED cases test_searchByTitle
        test.test_searchByTitle("Demo", std::list<Note>{demo, presentation});
        test.test_searchByTitle("Ideas", std::list<Note>{ideas});
        //FAILED cases test_searchByTitle
        test.test_searchByTitle("Ideas", std::list<Note>{blocked});
        test.test_searchByTitle("ToDo", std::list<Note>{ideas});
        //PASSED cases test_searchByText
        test.test_searchByText("every Friday: 16:00(NY time)", std::list<Note>{weekly_sync});
        test.test_searchByText("", std::list<Note>{ideas, backlog, presentation});
        //FAILED cases test_searchByText
        test.test_searchByText("Failed", std::list<Note>{weekly_sync});
        test.test_searchByText("weekly_sync", std::list<Note>{ideas, backlog, presentation});
        //PASSED cases test_searchByTag
        test.test_searchByTag("meeting", std::list<Note>{daily_meeting, retrospective, weekly_sync, PI_planning});
        test.test_searchByTag("keep in mind", std::list<Note>{todo});
        //FAILED cases test_searchByTag
        test.test_searchByTag("todo", std::list<Note>{daily_meeting, retrospective, presentation});
        test.test_searchByTag("Demo", std::list<Note>{ideas, backlog, presentation});
        //PASSED cases test_deleteNote
        test.test_deleteNote(demo);
        test.test_deleteNote(daily_meeting);
        test.test_deleteNote(retrospective);
        test.test_deleteNote(ideas);
    };
    std::cout << std::endl << "Thank you for your time. Have a nice day!" << std::endl;
    return 0;
}

