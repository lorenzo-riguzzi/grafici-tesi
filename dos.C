void dos(){
    TGraph* g = new TGraph("dos.dat", "%lg%lg"); 

    g->GetXaxis()->SetTitle("#font[132]{Energy (eV)}");
    g->GetYaxis()->SetTitle("#font[132]{Desnity of States (eV^{-1})}");
    g->SetTitle("#font[132]{Density of states of CsV_{3}Sb_{5}}");
    g->GetXaxis()->SetRangeUser(-7, 7);
    g->GetYaxis()->SetRangeUser(0, 50);
    g->GetXaxis()->SetLabelFont(132);
    g->GetYaxis()->SetLabelFont(132);
    //g->GetXaxis()->SetDecimals(kTRUE);
    //g->GetYaxis()->SetDecimals(kTRUE);

    TCanvas* c = new TCanvas();
    g->Draw("AL");
}