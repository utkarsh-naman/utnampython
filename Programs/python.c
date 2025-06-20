
/* Minimal main program -- everything is loaded from the library */

#include "Python.h"
#include <stdio.h>
#include <string.h>
#ifdef MS_WINDOWS
int
wmain(int argc, wchar_t** argv)
{
    char arg1[100] = { 0 };
    if (argc > 1) {
        wcstombs(arg1, argv[1], sizeof(arg1));
        if (strcmp(arg1, "info") == 0) {
            printf("github: https://github.com/utkarsh-naman/\n");
            printf("repo: https://github.com/utkarsh-naman/utnampython\n");
            printf("developer mail: mailto:truly.away@gmail.com\n");
            printf("linkedin: https://www.linkedin.com/in/utkarsh-naman\n");
            printf("portfolio: http://utkarshnaman.me/portfolio/\n");
            return 0;
        }
        else if (strcmp(arg1, "credits") == 0) {
            printf("utnampython - A custom cpython fork side/fun project by \"Utkarsh Naman.\"\n");
            printf("Hi. I'm Utkarsh Naman (short: UtNam). This side project of mine is a result of idea that hit me in late Feb 2025 and was finished before mid March 2025 \n");
            printf("I always have an itch to do something about what bugs me. \n");
            return 0;
        }
        else if (strcmp(arg1, "poet") == 0) {
            // Seed the random number generator with the current time
            srand((unsigned int)time(0));

            // Generate a random number between 1 and 11 (inclusive)
            int random_num = 1 + rand() % 11;
            if (random_num == 1) {
                printf("I would learn to sketch, only to see,\n");
                printf("your beauty captured, in every line by me.\n");
                printf("Each stroke whispers your graceful form.\n");
                printf("A timeless art which will have your warmth.\n");
                printf("\n");
                printf("I would study stars to know how they align,\n");
                printf("To find a moment, perfect and divine.\n");
                printf("A time when fate and dreams would interwine,\n");
                printf("Just to reach you, call you mine.\n");
                printf("\n");
                printf("I would master words, only to say,\n");
                printf("What thoughts you bring me, night & day.\n");
                printf("Only to read these, for you won't hear.\n");
                printf("The loudness of your silence, that pulls me near.\n");
                printf("\n");
                printf("For time itself, I would bend, shape, create.\n");
                printf("A perfect hour where we share our fate.\n");
                printf("For your presence won't add days to my life,\n");
                printf("But life to my days.\n");
                printf("\n");
                printf("So, let me be the hand that paints yours grace,\n");
                printf("Or the poet who immortalizes your face.\n");
                printf("For you, my love, I'd conquer every art,\n");
                printf("Even if it only brings me an inch closer to your heart.\n");

                return 0;
            }

            else if (random_num == 2) {
                printf("Days passed and died,\nand so did my feelings.\nShould I go back?\nwon\'t it undo my healings?\n\n"
                    "I want him to stay,\nI want to forgive\nOr is it that\nit\'s his attention all I seek?\n\n"
                    "The more it stays, the more it slays\nmakes me stand in mid fog and choose my way.\n\n"
                    "I don\'t care if he is wrong or right\nmaybe cuz I want him in my sight\nOh what strings of burden have been tied\n"
                    "Cutting or holding them, either gonna cost me my pride.\nI see no me in all that\'s left\nWas is it a mockery or a theft.\n"
                    "Ruin my feelings, ruin my heart.\nI\'m helpless since he already played his cards.\n");
                return 0;
            }

            else if (random_num == 3) {
                printf("After all\nyou too turned out to be same as others.\nMore like worn out threads of my sweater.\nLeaving you would set me out of the cage,\nI\'d be a free bird but with no feathers.\n");
                return 0;
            }

            else if (random_num == 4) {
                printf("I wish you could stay,\nI wish I could say.\nOnly if could express my feelings,\nI wouldn't have required these healings.\n");
                return 0;
            }

            else if (random_num == 5) {
                printf("It\'s been long since the 3rd of December,\n"
                    "I was your charity, a gift you don\'t remember.\n"
                    "You knew how much you were desired by me,\n"
                    "You hoped I\'d settle for less than the sea.\n\n"
                    "She deserves so much more, I won\'t disagree,\n"
                    "Her eyes, sky blue, her golden glow sunny.\n"
                    "Heather, if you\'re reading, you know who I envy,\n"
                    "It\'s freezing cold, though I burn with jealousy.\n\n"
                    "Your birthday invite arrived this Friday,\n"
                    "Was it penned from your heart or just forwarded away?\n"
                    "I would\'ve begged for a rain check, couldn\'t bear her,\n"
                    "Sharing the cake while I sip and hopelessly stare.\n\n"
                    "Those eyelashes flutter at me with pity,\n"
                    "Alone in a crowd with a glass of whiskey.\n"
                    "My blue dress, handed down just a day ago,\n"
                    "Her pale skin suits even the dullest shade of yellow.\n\n"
                    "I stole glances at you from across the room,\n"
                    "Oh, the smiles my loomy presence consume.\n"
                    "I wished you the best from a far-off place,\n"
                    "A wallflower bloomed beneath a red rose\'s haze.\n\n"
                    "Why would I ever kiss you?\n"
                    "All I want is for you to be happy too.\n"
                    "I hear the laughs you never had with me,\n"
                    "I smile at the sound so contentedly.\n\n"
                    "On a table left, your synthetic sweater,\n"
                    "Hope you gift her something much better.\n"
                    "I left what once felt like a home,\n"
                    "Tomorrow I\'ll make a new one alone.\n\n"
                    "You taught me a new way to live,\n"
                    "To love and keep my heart off my sleeve.\n"
                    "To find a world that had existed far beyond,\n"
                    "Of you, me, and Heather, all along.\n\n- Debadatta\n");
                return 0;
            }

            else if (random_num == 6) {
                printf("i savor my slow paced life\n"
                    "as if i\'m already 60 and tired\n"
                    "there was a rat race i lost\n"
                    "patiently let everyone cross\n"
                    "now i\'m in the middle of nowhere\n"
                    "drowning at nemo in silent prayer\n"
                    "someone playing acoustic at distant\n"
                    "i\'m sure they too lost their reason\n"
                    "the why, the where, what they pursue\n"
                    "some of us loathe this unyielding queue\n"
                    "Yet in this calm, I find my peace,\n"
                    "A fleeting moment, a sweet release.\n"
                    "The world may run, but I\'ll just stay,\n"
                    "Embracing life, my quiet way.\n\n- Debadatta\n");
                return 0;
            }

            else if (random_num == 7) {
                printf("A saba tuesday evening\n"
                    "I caged the fireflies in a jar\n"
                    "To guide u when the night was far\n"
                    "In my cruel hands, their freedom died\n"
                    "Not me, but u, reflected inside\n\n- Debadatta\n");
                return 0;
            }

            else if (random_num == 8) {
                printf("books left unread\n"
                    "films left unwatched\n"
                    "the endings i dread\n"
                    "wet shoulders i dodged\n\n"
                    "escaped a drowning tear\n"
                    "scars lay hiding\n"
                    "she lives in constant fear\n"
                    "all of this for nothing\n\n"
                    "grey clouds in dark sky\n"
                    "black boots on the edge\n"
                    "stood there till they dry\n"
                    "didn\'t jump off the ledge\n\n"
                    "didn\'t see what\n"
                    "didn\'t happen at all\n"
                    "for eternal she rot\n"
                    "it felt like a doll\n\n"
                    "she heard a myth\n"
                    "happily ever after\n"
                    "if not this then\n"
                    "nothing else matter\n\n"
                    "afraid of no failure\n"
                    "even if life won\n"
                    "this is stranger\n"
                    "not content a concern\n\n"
                    "unfortunate stories\n"
                    "needs no reader\n"
                    "moving through cities\n"
                    "seeking a bit sweeter\n\n"
                    "investing energy\n"
                    "and emotions alike\n"
                    "if endings are terribly\n"
                    "no need to write\n\n- Debadatta\n");
                return 0;
            }

            else if (random_num == 9) {
                printf("strange tears flowing down his eyes\n"
                    "my bones freeze as my brother cries\n"
                    "A pair of eyes I had once doubted\n"
                    "could ever let emotions be reflected\n\n"
                    "in the absence of a cushion to hold\n"
                    "while his back hit the floor hard and cold\n"
                    "in all these years of love\'s long drought\n"
                    "All the battles he bravely fought\n\n"
                    "even the stoics would hang their heads\n"
                    "at his deafening laugh when questions raised\n"
                    "the most surprising eyes that ever glistened\n"
                    "belongs to the only man that cared and listened\n\n"
                    "makes me wonder what made him let go\n"
                    "sharp roots of hemlock on his heart grow\n"
                    "perhaps all the weight he bore\n"
                    "from carrying me and the family lore\n\n"
                    "Why should he have kept them hidden?\n"
                    "What makes a crying man feel weakened?\n"
                    "Which weapons do hurt people lack\n"
                    "That their armor deemed to have a wide crack\n\n"
                    "the fabric of space woven through me\n"
                    "his black hole would better float at sea\n"
                    "breaking through my delicate strings\n"
                    "how sharpest canes support old kings\n\n"
                    "Not too strong and not too frail\n"
                    "I try to fight the same vicious tale\n"
                    "And I stumbled deeper than he fell\n"
                    "the floor felt colder, and it hurt like hell\n\n"
                    "I wasn\'t tied with society\'s chains\n"
                    "I could cry for support while it pains\n"
                    "Someone lend a hand to pull me through\n"
                    "I look up to find a gaze I once knew\n\n"
                    "met with deep set eyes tired of lights\n"
                    "barely knew how to keep fake smiles\n"
                    "bestowed the only directions he assumed\n"
                    "while he coughed on last bit of air I consumed\n\n"
                    "I move ahead, leaving him to suffocate,\n"
                    "He swears he\'ll follow the path I create.\n"
                    "But somewhere along, I forget,\n"
                    "Distracted and buried in a heavy debt.\n\n"
                    "No one knew the way back or ahead\n"
                    "is this where my brother hurt and bled\n"
                    "Now I stand where his shadow fades,\n"
                    "Lost in silence, unsure and afraid\n\n"
                    "I rest on nameless milestone\n"
                    "long for long till my ashes get blown.\n"
                    "So the wind could tell him where I laid\n"
                    "till my skin wrinkled and hair grayed\n\n- Debadatta\n");
                return 0;
            }

            else if (random_num == 10) {
                printf("Aisa toh nahi ki sirf hum use pasand karte hai\n"
                    "Mere jaise, mujhse behter, hazaaron uspe marte hai.\n"
                    "Mera uspe koi haq nahi\n"
                    "Milega usey mujhse behter is baat ka koi shaq nahi.\n"
                    "Mera naam le wo ek baar toh hum  aabaad ho jayenge,\n"
                    "Agar mili nazrein ek baar, hum barbaad ho jayenge.\n"
                    "Khoobsurat itni ki Duniyaa usey hoor maanti hai\n"
                    "Mai bhi hoon duniya mein kya wo ye jaanti hai.\n\n- rayonium\n");
                return 0;
            }

            else if (random_num == 11) {
                printf("Where the stars watched\n"
                    "I could see you.\n"
                    "I could see us basking in the moonlight.\n"
                    "The stars in the sky,\n"
                    "The night falling down,\n"
                    "The dim yellow light\n"
                    "Making it's way though the trees\n"
                    "Around us,\n"
                    "The grass with its lush green hue,\n"
                    "The cool breeze blowing delicately,\n"
                    "Gently touching your face\n"
                    "And I was looking into your eyes\n"
                    "Glowing like the stars,\n"
                    "Intoxicating me.\n"
                    "My fingers wandering through your hair,\n"
                    "I was caressing your body,\n"
                    "I was going deeper into you,\n"
                    "I was melting in your embrace\n"
                    "And feeling your warmth,\n"
                    "I was in my home.\n"
                    "I kissed you,\n"
                    "Kissed your soul,\n"
                    "With all the tenderness,\n"
                    "With all the love,\n"
                    "With all my passion.\n"
                    "I got lost in your light,\n"
                    "Lost in my fairy tale\n\n- Jojo.\n");
                return 0;
            }
            return 0;
        }
    }
    return Py_Main(argc, argv);
}
#else
int
main(int argc, char** argv)
{
    if (argc > 1) {
        if (strcmp(argv[1], "info") == 0) {
            printf("github: https://github.com/utkarsh-naman/\n");
            printf("repo: https://github.com/utkarsh-naman/utnampython\n");
            printf("developer mail: mailto:truly.away@gmail.com\n");
            printf("linkedin: https://www.linkedin.com/in/utkarsh-naman\n");
            printf("portfolio: http://utkarshnaman.me/portfolio/\n");
            return 0;
        }
        else if (strcmp(argv[1], "credits") == 0) {
            printf("utnampython - A custom cpython fork side\/fun project by \"Utkarsh Naman.\"\n");
            printf("Hi. I'm Utkarsh Naman (short: UtNam). This side project of mine is a result of idea that hit me in late Feb 2025 and was finished before mid March 2025 \n");
            printf("I always have an itch to do something about what bugs me. \n");
            return 0;
        }
        else if (strcmp(argv[1], "poet") == 0) {
            // Seed the random number generator with the current time
            srand((unsigned int)time(0));

            // Generate a random number between 1 and 11 (inclusive)
            int random_num = 1 + rand() % 11;
            if (random_num == 1) {
                printf("I would learn to sketch, only to see,\n");
                printf("your beauty captured, in every line by me.\n");
                printf("Each stroke whispers your graceful form.\n");
                printf("A timeless art which will have your warmth.\n");
                printf("\n");
                printf("I would study stars to know how they align,\n");
                printf("To find a moment, perfect and divine.\n");
                printf("A time when fate and dreams would interwine,\n");
                printf("Just to reach you, call you mine.\n");
                printf("\n");
                printf("I would master words, only to say,\n");
                printf("What thoughts you bring me, night & day.\n");
                printf("Only to read these, for you won't hear.\n");
                printf("The loudness of your silence, that pulls me near.\n");
                printf("\n");
                printf("For time itself, I would bend, shape, create.\n");
                printf("A perfect hour where we share our fate.\n");
                printf("For your presence won't add days to my life,\n");
                printf("But life to my days.\n");
                printf("\n");
                printf("So, let me be the hand that paints yours grace,\n");
                printf("Or the poet who immortalizes your face.\n");
                printf("For you, my love, I'd conquer every art,\n");
                printf("Even if it only brings me an inch closer to your heart.\n");

                return 0;
            }

            else if (random_num == 2) {
                printf("Days passed and died,\nand so did my feelings.\nShould I go back?\nwon\'t it undo my healings?\n\n"
                    "I want him to stay,\nI want to forgive\nOr is it that\nit\'s his attention all I seek?\n\n"
                    "The more it stays, the more it slays\nmakes me stand in mid fog and choose my way.\n\n"
                    "I don\'t care if he is wrong or right\nmaybe cuz I want him in my sight\nOh what strings of burden have been tied\n"
                    "Cutting or holding them, either gonna cost me my pride.\nI see no me in all that\'s left\nWas is it a mockery or a theft.\n"
                    "Ruin my feelings, ruin my heart.\nI\'m helpless since he already played his cards.\n");
                return 0;
            }

            else if (random_num == 3) {
                printf("After all\nyou too turned out to be same as others.\nMore like worn out threads of my sweater.\nLeaving you would set me out of the cage,\nI\'d be a free bird but with no feathers.\n");
                return 0;
            }

            else if (random_num == 4) {
                printf("I wish you could stay,\nI wish I could say.\nOnly if could express my feelings,\nI wouldn't have required these healings.\n");
                return 0;
            }

            else if (random_num == 5) {
                printf("It\'s been long since the 3rd of December,\n"
                    "I was your charity, a gift you don\'t remember.\n"
                    "You knew how much you were desired by me,\n"
                    "You hoped I\'d settle for less than the sea.\n\n"
                    "She deserves so much more, I won\'t disagree,\n"
                    "Her eyes, sky blue, her golden glow sunny.\n"
                    "Heather, if you\'re reading, you know who I envy,\n"
                    "It\'s freezing cold, though I burn with jealousy.\n\n"
                    "Your birthday invite arrived this Friday,\n"
                    "Was it penned from your heart or just forwarded away?\n"
                    "I would\'ve begged for a rain check, couldn\'t bear her,\n"
                    "Sharing the cake while I sip and hopelessly stare.\n\n"
                    "Those eyelashes flutter at me with pity,\n"
                    "Alone in a crowd with a glass of whiskey.\n"
                    "My blue dress, handed down just a day ago,\n"
                    "Her pale skin suits even the dullest shade of yellow.\n\n"
                    "I stole glances at you from across the room,\n"
                    "Oh, the smiles my loomy presence consume.\n"
                    "I wished you the best from a far-off place,\n"
                    "A wallflower bloomed beneath a red rose\'s haze.\n\n"
                    "Why would I ever kiss you?\n"
                    "All I want is for you to be happy too.\n"
                    "I hear the laughs you never had with me,\n"
                    "I smile at the sound so contentedly.\n\n"
                    "On a table left, your synthetic sweater,\n"
                    "Hope you gift her something much better.\n"
                    "I left what once felt like a home,\n"
                    "Tomorrow I\'ll make a new one alone.\n\n"
                    "You taught me a new way to live,\n"
                    "To love and keep my heart off my sleeve.\n"
                    "To find a world that had existed far beyond,\n"
                    "Of you, me, and Heather, all along.\n- Debadatta\n");
                return 0;
            }

            else if (random_num == 6) {
                printf("i savor my slow paced life\n"
                    "as if i\'m already 60 and tired\n"
                    "there was a rat race i lost\n"
                    "patiently let everyone cross\n"
                    "now i\'m in the middle of nowhere\n"
                    "drowning at nemo in silent prayer\n"
                    "someone playing acoustic at distant\n"
                    "i\'m sure they too lost their reason\n"
                    "the why, the where, what they pursue\n"
                    "some of us loathe this unyielding queue\n"
                    "Yet in this calm, I find my peace,\n"
                    "A fleeting moment, a sweet release.\n"
                    "The world may run, but I\'ll just stay,\n"
                    "Embracing life, my quiet way.\n\n- Debadatta\n");
                return 0;
            }

            else if (random_num == 7) {
                printf("A saba tuesday evening\n"
                    "I caged the fireflies in a jar\n"
                    "To guide u when the night was far\n"
                    "In my cruel hands, their freedom died\n"
                    "Not me, but u, reflected inside\n\n- Debadatta\n");
                return 0;
            }

            else if (random_num == 8) {
                printf("books left unread\n"
                    "films left unwatched\n"
                    "the endings i dread\n"
                    "wet shoulders i dodged\n\n"
                    "escaped a drowning tear\n"
                    "scars lay hiding\n"
                    "she lives in constant fear\n"
                    "all of this for nothing\n\n"
                    "grey clouds in dark sky\n"
                    "black boots on the edge\n"
                    "stood there till they dry\n"
                    "didn\'t jump off the ledge\n\n"
                    "didn\'t see what\n"
                    "didn\'t happen at all\n"
                    "for eternal she rot\n"
                    "it felt like a doll\n\n"
                    "she heard a myth\n"
                    "happily ever after\n"
                    "if not this then\n"
                    "nothing else matter\n\n"
                    "afraid of no failure\n"
                    "even if life won\n"
                    "this is stranger\n"
                    "not content a concern\n\n"
                    "unfortunate stories\n"
                    "needs no reader\n"
                    "moving through cities\n"
                    "seeking a bit sweeter\n\n"
                    "investing energy\n"
                    "and emotions alike\n"
                    "if endings are terribly\n"
                    "no need to write\n\n- Debadatta\n");
                return 0;
            }

            else if (random_num == 9) {
                printf("strange tears flowing down his eyes\n"
                    "my bones freeze as my brother cries\n"
                    "A pair of eyes I had once doubted\n"
                    "could ever let emotions be reflected\n\n"
                    "in the absence of a cushion to hold\n"
                    "while his back hit the floor hard and cold\n"
                    "in all these years of love\'s long drought\n"
                    "All the battles he bravely fought\n\n"
                    "even the stoics would hang their heads\n"
                    "at his deafening laugh when questions raised\n"
                    "the most surprising eyes that ever glistened\n"
                    "belongs to the only man that cared and listened\n\n"
                    "makes me wonder what made him let go\n"
                    "sharp roots of hemlock on his heart grow\n"
                    "perhaps all the weight he bore\n"
                    "from carrying me and the family lore\n\n"
                    "Why should he have kept them hidden?\n"
                    "What makes a crying man feel weakened?\n"
                    "Which weapons do hurt people lack\n"
                    "That their armor deemed to have a wide crack\n\n"
                    "the fabric of space woven through me\n"
                    "his black hole would better float at sea\n"
                    "breaking through my delicate strings\n"
                    "how sharpest canes support old kings\n\n"
                    "Not too strong and not too frail\n"
                    "I try to fight the same vicious tale\n"
                    "And I stumbled deeper than he fell\n"
                    "the floor felt colder, and it hurt like hell\n\n"
                    "I wasn\'t tied with society\'s chains\n"
                    "I could cry for support while it pains\n"
                    "Someone lend a hand to pull me through\n"
                    "I look up to find a gaze I once knew\n\n"
                    "met with deep set eyes tired of lights\n"
                    "barely knew how to keep fake smiles\n"
                    "bestowed the only directions he assumed\n"
                    "while he coughed on last bit of air I consumed\n\n"
                    "I move ahead, leaving him to suffocate,\n"
                    "He swears he\'ll follow the path I create.\n"
                    "But somewhere along, I forget,\n"
                    "Distracted and buried in a heavy debt.\n\n"
                    "No one knew the way back or ahead\n"
                    "is this where my brother hurt and bled\n"
                    "Now I stand where his shadow fades,\n"
                    "Lost in silence, unsure and afraid\n\n"
                    "I rest on nameless milestone\n"
                    "long for long till my ashes get blown.\n"
                    "So the wind could tell him where I laid\n"
                    "till my skin wrinkled and hair grayed\n\n- Debadatta\n");
                return 0;
            }

            else if (random_num == 10) {
                printf("Aisa toh nahi ki sirf hum use pasand karte hai\n"
                    "Mere jaise, mujhse behter, hazaaron uspe marte hai.\n"
                    "Mera uspe koi haq nahi\n"
                    "Milega usey mujhse behter is baat ka koi shaq nahi.\n"
                    "Mera naam le wo ek baar toh hum  aabaad ho jayenge,\n"
                    "Agar mili nazrein ek baar, hum barbaad ho jayenge.\n"
                    "Khoobsurat itni ki Duniyaa usey hoor maanti hai\n"
                    "Mai bhi hoon duniya mein kya wo ye jaanti hai.\n\n- rayonium\n");
                return 0;
            }

            else if (random_num == 11) {
                printf("Where the stars watched\n"
                    "I could see you.\n"
                    "I could see us basking in the moonlight.\n"
                    "The stars in the sky,\n"
                    "The night falling down,\n"
                    "The dim yellow light\n"
                    "Making it's way though the trees\n"
                    "Around us,\n"
                    "The grass with its lush green hue,\n"
                    "The cool breeze blowing delicately,\n"
                    "Gently touching your face\n"
                    "And I was looking into your eyes\n"
                    "Glowing like the stars,\n"
                    "Intoxicating me.\n"
                    "My fingers wandering through your hair,\n"
                    "I was caressing your body,\n"
                    "I was going deeper into you,\n"
                    "I was melting in your embrace\n"
                    "And feeling your warmth,\n"
                    "I was in my home.\n"
                    "I kissed you,\n"
                    "Kissed your soul,\n"
                    "With all the tenderness,\n"
                    "With all the love,\n"
                    "With all my passion.\n"
                    "I got lost in your light,\n"
                    "Lost in my fairy tale\n\n- Jojo.\n");
                return 0;
            }
            return 0;
        }
    }
    return Py_BytesMain(argc, argv);
}
#endif
