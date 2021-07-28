/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>


/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);


/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "GLSample";
    RegisterClass (&wc);

    /* create main window */
    hWnd = CreateWindow (
      "GLSample", "OpenGL Sample", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 256, 256,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT);

            glPushMatrix ();
            
            glBegin (GL_POLYGON);
            glColor3f (0.69,0.69,0.69);     
            glVertex2f(-10,0.3);		//trotoar atas
            glVertex2f(-10,0.25);
            glVertex2f(10,0.25);
            glVertex2f(10,0.3);
            
            glEnd ();
        
            glBegin (GL_POLYGON);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (-0.4,0.2);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (-0.45,0.15);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (-0.45,-0.1);	//body mobil
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (0.4,-0.1);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (0.4,0.15);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (0.35,0.2);
            
            glEnd ();
            
             glBegin (GL_POLYGON);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (-0.03,0.35);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex2f (-0.18,0.2);		// atap mobil
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.25,0.2);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (0.25,0.25);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (0.21,0.35);
            
            glEnd ();
            
            glBegin (GL_POLYGON); 
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex2f (-0.02,0.31);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (-0.09,0.23); 	//jendela 1
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.1,0.23);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.1,0.31);
            
            glEnd ();
            
            glBegin (GL_POLYGON); 
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex2f (0.11,0.31);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (0.11,0.23); 	//jendela 2
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.22,0.23);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex2f (0.18,0.31);
            
            glEnd ();
            
            glBegin (GL_POLYGON);
            glColor3f (0.69,0.69,0.69);     //trotoar bawah
            glVertex2f(-10,-0.75);
            glVertex2f(-10,-0.85);
            glVertex2f(10,-0.75);
            glVertex2f(10,-0.85);
            
            glEnd ();
            
            glBegin (GL_POLYGON);
            glColor3f (1.0,1.0,1.0);     
			glVertex2f(-0.82,-0.23);		//marka jalan
            glVertex2f(-0.82,-0.26);
            glVertex2f(-0.42,-0.26);
            glVertex2f(-0.42,-0.23);
            
            glEnd ();
            
            glBegin (GL_POLYGON);
            glColor3f (1.0,1.0,1.0);     
			glVertex2f(-0.22,-0.23);		//marka jalan 2
            glVertex2f(-0.22,-0.26);
            glVertex2f(0.22,-0.26);
            glVertex2f(0.22,-0.23);
            
            glEnd ();
            
            glBegin (GL_POLYGON);
            glColor3f (1.0,1.0,1.0);     
			glVertex2f(0.42,-0.23);		//marka jalan 3
            glVertex2f(0.42,-0.26);
            glVertex2f(0.82,-0.26);
            glVertex2f(0.82,-0.23);
            glEnd ();
            
             glBegin (GL_POLYGON);
            glColor3f (0.69f, 0.69f, 0.69f);   glVertex2f (-0.35,0.0);
            glColor3f (0.69f, 0.69f, 0.69f);   glVertex2f (-0.35,-0.15); //ban depan
            glColor3f (0.69f, 0.69f, 0.69f);   glVertex2f (-0.20,-0.15);
            glColor3f (0.69f, 0.69f, 0.69f);   glVertex2f (-0.20,0.0);
            glEnd();
            
            
            glBegin (GL_POLYGON);
            glColor3f (0.69f, 0.69f, 0.69f);   glVertex2f (0.30,0.0);
            glColor3f (0.69f, 0.69f, 0.69f);   glVertex2f (0.30,-0.15);		//ban belakang
            glColor3f (0.69f, 0.69f, 0.69f);   glVertex2f (0.15,-0.15);
            glColor3f (0.69f, 0.69f, 0.69f);   glVertex2f (0.15,0.0);
            glEnd(); 
			 
			             
            glFlush();
            glPopMatrix ();

            SwapBuffers (hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}
